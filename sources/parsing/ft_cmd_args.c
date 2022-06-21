/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:33 by guyar             #+#    #+#             */
/*   Updated: 2022/06/20 15:46:04 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_split_cmd_args(t_process *process)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isspace(process->cmd[i]) == 1)
		i++;
	process->cmd = process->cmd + i;
	tmp = ft_take_cmd(process);
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

char	*ft_take_cmd(t_process *process)
{
	char	*ret;
	char	**spited;
	int		i;

	i = 0;
	ft_clean_str(&process->cmd);
	spited = ft_split_bash(process->cmd);
	ret = ft_strdup(spited[i]);
	i++;
	process->args = ft_strdup(spited[i]);
	while (spited[++i])
	{
		process->args = ft_strjoin_free_first(process->args, " ");
		process->args = ft_strjoin_free(process->args, spited[i]);
	}
	free(spited);
	return (ret);
}

void	ft_clean_str(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *str;
	*str = ft_strtrim(tmp, " ");
	free(tmp);
}
