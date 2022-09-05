/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/07/01 08:57:08 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_command(t_minishell *main)
{
	int			i;
	char		*home;
	t_process	*tmp;

	i = 0;
	home = NULL;
	main->process = ft_init_process(main->splitcmd[i]);
	while (main->splitcmd[++i])
	{
		tmp = ft_init_process(main->splitcmd[i]);
		addprocess(&main->process, tmp);
	}
	tmp = main->process;
	ft_create_command_loop(tmp, main, home);
}

void	ft_create_command_loop(t_process *tmp, t_minishell *main, char *home)
{
	while (tmp)
	{
		ft_clear_cmd(tmp);
		ft_redirec(tmp, main);
		if (ft_strlen(tmp->cmd) == 0)
		{
			g_error = 1;
			return ;
		}
		ft_check_dollar(&tmp->cmd, main->env, 0);
		home = ft_getenv("HOME", main->env);
		ft_split_cmd_args(tmp, home);
		free(home);
		tmp = tmp->next;
	}
}

void	addprocess(t_process **alst, t_process *new)
{
	t_process	*t;
	int			i;

	i = 0;
	if (alst && *alst)
	{
		t = *alst;
		while (t->next)
		{
			t = t->next;
			i++;
		}
		t->next = new;
	}
	else if (alst)
		*alst = new;
	new->process_nb = i;
}

t_process	*ft_init_process(char *str)
{
	t_process	*l;

	l = malloc(sizeof(t_process));
	if (!l)
		return (0);
	l->args = NULL;
	l->cmd = ft_strdup(str);
	l->outfd = 0;
	l->infd = 0;
	l->outfile = NULL;
	l->infile = NULL;
	l->next = NULL;
	l->hd_stop = NULL;
	l->pid = 0;
	l->fullcmd = NULL;
	l->all_redirec = NULL;
	return (l);
}
