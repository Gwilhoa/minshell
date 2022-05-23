/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:56:36 by guyar             #+#    #+#             */
/*   Updated: 2022/05/20 16:16:52 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h" 

void ft_clear_cmd(t_process *process)
{
	int i;
	int start;
	int end;

	process->redirec = malloc(sizeof(char) * 2);
	process->redirec[0] = '\0';
	i = -1;
	while (process->cmd[++i])
	{
		if (process->cmd[i] == '>' || process->cmd[i] == '<')
		{	
			start = i;
			end = ft_clean_till(process->cmd, start);
			process->redirec = ft_strjoin(process->redirec, ft_substr(process->cmd, start, (end - start)));
			process->cmd = ft_clean_str(process->cmd, (start), (end));
			i = 0;
		}
	}
}

int ft_clean_till(char *str, int i)
{
	while (str[i] == '<' 
		|| str[i] == '>' 
		|| str[i] == ' ')
		i++;
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

char *ft_clean_str(char *str, int start, int end)
{
	int i;
	char *tmp;
	
	i = 0;
	tmp = ft_strjoin(ft_substr(str, i, start), ft_substr(str, end, (ft_strlen(str))));
	free(str);
	return (tmp);
}