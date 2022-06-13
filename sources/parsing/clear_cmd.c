/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:56:36 by guyar             #+#    #+#             */
/*   Updated: 2022/06/13 15:04:21 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_cmd(t_process *process)
{
	int	i;
	int	start;
	int	end;

	process->redirec = malloc(sizeof(char) * 1);
	process->redirec[0] = '\0';
	i = -1;
	while (process->cmd[++i])
	{
		if (process->cmd[i] == '>' || process->cmd[i] == '<')
		{	
			start = i;
			end = ft_end_redirec(process->cmd, start);
			process->redirec = ft_strjoin_free(process->redirec, \
			ft_substr(process->cmd, start, (end - start)));
			ft_clean_str(&process->cmd);
			i = 0;
		}
	}
}

int	ft_end_redirec(char *str, int i)
{
	int	q;
	int	q2;

	q = 0;
	q2 = 0;
	while (str[i] == '<' \
		|| str[i] == '>' \
		|| str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if (str[i] == ' ' && q == 0 && q2 == 0)
			return (i);
		i++;
	}
	return (i);
}
