/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/27 22:01:13 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_command(t_minishell *main)
{
	int			i;
	char		*home;
	t_process	*tmp;

	i = 0;
	main->process = ft_init_process(main->splitcmd[i]);
	while (main->splitcmd[++i])
	{
		tmp = ft_init_process(main->splitcmd[i]);
		addprocess(&main->process, tmp);
	}
	tmp = main->process;
	while (tmp)
	{
		ft_clear_cmd(tmp);			// clear les redirect
		ft_redirec(tmp, main);
		home = ft_getenv("HOME", main->env);
		ft_split_cmd_args(tmp, home);
		free(home);
		ft_check_dollar(&tmp->cmd, main->env, 0, 0);
		ft_delquotes(&tmp->cmd);
		if (tmp->args != NULL)
			ft_check_dollar(&tmp->args, main->env, 0, 0);
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
	l->cmd = ft_strdup(str);
	l->outfd = 0;
	l->infd = 0;
	l->outfile = NULL;
	l->infile = NULL;
	l->next = NULL;
	l->heredoc = NULL;
	l->hd_stop = NULL;
	l->pid = 0;
	l->fullcmd = NULL;
	l->all_redirec = NULL;
	return (l);
}
