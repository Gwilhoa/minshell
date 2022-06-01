/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:51:56 by guyar             #+#    #+#             */
/*   Updated: 2022/06/01 19:15:38 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_search_heredoc(t_process *process)
{
	int i;

	i = 0;
	while (process->all_redirec[i])
	{
		if (process->all_redirec[i][0] == '<' && process->all_redirec[i][1] == '<')
		ft_in_hd(process, i);
		i++;
	}
}

void	ft_in_hd(t_process *process, int i)
{
	int	s;

	process->code = 2;
	s = process->code;
	while (process->all_redirec[i][s] == ' ')
		s++;
	if (process->all_redirec[i][s] == 0)
	{
		g_error = ERRO_SYNTAXE;
		return ;
	}
	process->hd_stop = ft_strdup(process->all_redirec[i] + s);
	process->infile = NULL;
	ft_heredoc(process, process->hd_stop);
}

void	ft_heredoc(t_process *process, char *str)
{
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char) * 1);
	tmp[0] = '\0';
	i = ft_strcmp(str, tmp);
	process->heredoc = malloc(sizeof(char) * 1);
	process->heredoc[0] = '\0';
	while (i != 0)
	{
		tmp = readline("heredoc> ");
		i = ft_strcmp(str, tmp);
		if (i != 0)
			process->heredoc = ft_strjoin_hd(process->heredoc, tmp);
	}
}
