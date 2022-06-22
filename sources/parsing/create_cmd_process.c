/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/22 11:18:37 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_command(t_minishell *main)
{
	int			i;
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
		ft_clear_cmd(tmp);
		ft_redirec(tmp, main);
		ft_split_cmd_args(tmp);
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
	l->cmd = str;
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
