/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:33 by guyar             #+#    #+#             */
/*   Updated: 2022/05/31 15:45:17 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_args(t_process *process)
{
	int		i;
	char	*tmp;

	if (process->args == NULL)
		return ;
	i = ft_strlen(process->args) - 1;
	while (process->args[i] == ' ')
		i--;
	tmp = ft_substr(process->args, 0, i + 1);
	process->args = tmp;
}

void	ft_cmd_args(t_process *process)
{
	int		i;
	char	*tmp;

	i = 0;
	while (process->cmd[i] == ' ')
		i++;
	process->cmd = process->cmd + i;
	tmp = ft_strdup(ft_take_cmd(process));
	ft_take_args(process, tmp);
	ft_clean_args(process);
	process->cmd = tmp;
}

void	ft_take_args(t_process *process, char	*tmp)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(process->cmd);
	if (len == ft_strlen(tmp))
	{
		process->args = NULL;
		return ;
	}
	process->cmd = process->cmd + ft_strlen(tmp);
	while (process->cmd[i] == ' ')
		i++;
	if (process->cmd[i] == 0)
	{
		process->args = NULL;
		return ;
	}
	process->args = process->cmd + i;
}

char	*ft_take_cmd(t_process *process)
{
	int		i;
	int		wordlen;
	char	*tmp;

	i = 0;
	wordlen = i;
	while (process->cmd[wordlen] != ' ' && process->cmd[wordlen] != 0)
		wordlen++;
	tmp = ft_substr(process->cmd, i, (wordlen - i));
	return (tmp);
}
