/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:56:36 by guyar             #+#    #+#             */
/*   Updated: 2022/06/27 22:38:03 by guyar            ###   ########.fr       */
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
			remove_file(&process->cmd, start, end);
			ft_clean_str(&process->cmd);
			i = -1;
		}
	}
}

void	remove_file(char **str, int start, int end)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *str;
	tmp = ft_strjoin_free(ft_substr(tmp, i, start), \
	ft_substr(tmp, end, (ft_strlen(tmp))));
	free(*str);
	*str = tmp;
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
