/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:51:56 by guyar             #+#    #+#             */
/*   Updated: 2022/06/01 17:12:09 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			process->heredoc = ft_strjoin(process->heredoc, tmp);
	}
}
