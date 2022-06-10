/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:11:33 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 20:25:26 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cmd_args(t_process *process)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isspace(process->cmd[i]) == 1)
		i++;
	process->cmd = process->cmd + i;
	tmp = ft_take_cmd(process);
	ft_clean_args(process);
 	process->cmd = tmp;
}

void	ft_clean_args(t_process *process)			// fonction incomplete supprimer tout les espaces entre les args;
{
	int		i;
	char	*tmp;

	if (process->args == NULL)
		return ;
	i = ft_strlen(process->args) - 1;
	while (ft_isspace(process->args[i]) == 1)
		i--;
	tmp = ft_substr(process->args, 0, i + 1);
	process->args = tmp;
}

char	*ft_take_cmd(t_process *process)
{
	char	*ret;
	char	**spited;
	int		i;

	i = 0;
	spited = ft_split_bash(process->cmd);
	ret = ft_strdup(spited[i]);
	i++;
	process->args = ft_strdup(spited[i]);
	while (spited[++i])
		process->args = ft_strjoin(process->args, spited[i]);
	ft_free_matrix(spited);
	free(spited);
	return (ret);
}
