/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/30 10:55:04 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *mini, t_process *process)
{
	int			tmp;

	tmp = 0;
	close(mini->default_infd);
	close(mini->default_outfd);
	if (process == NULL || process->args == NULL)
	{
		ft_printf("exit\n");
		exit(g_error);
	}
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
