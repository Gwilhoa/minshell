/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:33 by guyar             #+#    #+#             */
/*   Updated: 2022/05/23 18:12:04 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd_args(t_process *process)
{
	int		i;
	char	*tmp;

	i = 0;
	ft_take_args(process);
	tmp = ft_take_cmd(process);
	free(process->cmd);
	process->cmd = tmp;
}

void	ft_take_args(t_process *process)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(process->cmd) - 1;
	while (process->cmd[i] == ' ')
		i++;
	while (process->cmd[i] != ' ')
		i++;
	while (process->cmd[i] == ' ')
		i++;
	while (process->cmd[len] == ' ')
		len--;
	len++;
	process->args = ft_substr(process->cmd, i, ((len - i)));
}

char	*ft_take_cmd(t_process *process)
{
	int		i;
	int		wordlen;
	char	*tmp;

	i = 0;
	while (process->cmd[i] == ' ')
		i++;
	wordlen = i;
	while (process->cmd[wordlen] != ' ')
		wordlen++;
	tmp = ft_substr(process->cmd, i, (wordlen - i));
	return (tmp);
}