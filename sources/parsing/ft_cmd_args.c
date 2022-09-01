/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:33 by guyar             #+#    #+#             */
/*   Updated: 2022/09/01 11:29:02 by gchatain         ###   ########lyon.fr   */
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
	tmp = ft_take_cmd(process);
	if (ft_strcmp(tmp, "~") == 0)
	{
		free(tmp);
		tmp = ft_strdup(home);
	}
	ft_clean_args(process, home);
	if (process->cmd != NULL)
		free(process->cmd);
	process->cmd = tmp;
}

void	ft_clean_args(t_process *process, char *home)
{
	int		i;
	char	*tmp;

	if (process->args == NULL)
		return ;
	i = ft_strlen(process->args) - 1;
	while (ft_isspace(process->args[i]) == 1)
		i--;
	tmp = ft_substr(process->args, 0, i + 1);
	if (ft_strcmp(tmp, "~") == 0)
	{
		free(tmp);
		tmp = ft_strdup(home);
	}
	if (process->args != NULL)
		free(process->args);
	process->args = tmp;
}

char	*ft_take_cmd(t_process *process)
{
	char	*ret;
	char	**spited;
	int		i;

	i = 0;
	ft_clean_str(&process->cmd);
	spited = ft_split_bash(process->cmd);
	ret = ft_strdup(spited[0]);
	while (spited[++i])
	{
		if (i == 1)
			process->args = ft_strdup("");
		else
			process->args = ft_strjoin_free_first(process->args, " ");
		process->args = ft_strjoin_free_first(process->args, spited[i]);
	}
	ft_free_matrix(spited);
	free(spited);
	ft_delquotes(&ret);
	return (ret);
}

void	ft_clean_str(char **str)
{
	*str = ft_strtrim2(*str, " ");
}
