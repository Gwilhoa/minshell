/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:33 by guyar             #+#    #+#             */
/*   Updated: 2022/06/28 13:45:05 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_cmd_args(t_process *process, char *home)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (ft_isspace(process->cmd[i]) == 1)
		i++;
	tmp2 = ft_strdup(process->cmd + i);
	free(process->cmd);
	process->cmd = tmp2;
	tmp = ft_take_cmd(process, home);
	ft_clean_args(process);
	if (process->cmd != NULL)
		free(process->cmd);
	process->cmd = tmp;
}

void	ft_clean_args(t_process *process)
{
	int		i;
	char	*tmp;

	if (process->args == NULL)
		return ;
	i = ft_strlen(process->args) - 1;
	while (ft_isspace(process->args[i]) == 1)
		i--;
	tmp = ft_substr(process->args, 0, i + 1);
	if (process->args != NULL)
		free(process->args);
	process->args = tmp;
}

char	*ft_take_cmd(t_process *process, char *home)
{
	char	*ret;
	char	**spited;
	int		i;

	i = 0;
	ft_clean_str(&process->cmd);
	spited = ft_split_bash(process->cmd);
	while (spited[++i])
	{
		if (ft_strcmp(spited[i], "~") == 0)
			ft_strreplace(&spited[i], home);
	}
	i = 0;
	ret = ft_strdup(spited[i++]);
	process->args = ft_strdup(spited[i++]);
	while (spited[i])
	{
		process->args = ft_strjoin_free_first(process->args, " ");
		process->args = ft_strjoin_free_first(process->args, spited[i]);
		i++;
	}
	ft_free_matrix(spited);
	free(spited);
	return (ret);
}

void	ft_clean_str(char **str)
{
	*str = ft_strtrim2(*str, " ");
}
