/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/04 14:43:16 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *mini, t_process *process)
{
	int			tmp;
	char		**splitbash;

	if (process == NULL || process->args == NULL)
	{
		ft_printf("exit\n");
		exit(g_error);
	}
	splitbash = ft_split_bash(process->args);
	if (ft_isdigit(process->args[0]) == 1
		&& ft_matrix_size((const char **)splitbash) > 1)
	{
		ft_printf("exit\nbash: exit: too many argument\n");
		g_error = 127;
		return ;
	}
	tmp = 0;
	close(mini->default_infd);
	close(mini->default_outfd);
	ft_exit_code(mini, process, tmp);
}

void	ft_exit_code(t_minishell *mini, t_process *process, int tmp)
{
	int	i;

	i = -1;
	(void) mini;
	while (process->args[++i])
	{
		if (ft_isdigit(process->args[i]) == 0)
		{
			ft_printf("exit: %s: numeric argument required\n", process->args);
			exit(255);
		}
		else
		{
			tmp = ft_atoi(process->args);
			exit(tmp % 256);
		}
	}	
}
