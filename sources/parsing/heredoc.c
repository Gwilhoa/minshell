/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:51:56 by guyar             #+#    #+#             */
/*   Updated: 2022/05/31 18:59:30 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_heredoc(t_process *process, char *str)
{
    char *tmp;
    int i;
    
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