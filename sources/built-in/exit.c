/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/25 17:49:33 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *mini, t_process *process)
{
	int			tmp;

	tmp = 0;
	close(mini->default_infd);
	close(mini->default_outfd);
	ft_free_matrix(mini->env);
	if (process == NULL || process->args == NULL)
	{
		ft_printf("exit\n");
		g_error = 0;
		exit(0);
	}
	ft_exit_code(mini, process, tmp);
}

void	ft_exit_code(t_minishell *mini, t_process *process, int tmp)
{
	int	i;

	i = -1;
	while (process->args[++i])
	{
		if (ft_isdigit(process->args[i]) == 0)
		{
			ft_printf("exit: %s: numeric argument required\n", process->args);
			ft_free_struc(mini);
			free(mini);
			ft_free_process(process);
			free(process);
			exit(255);
		}
		else
		{
			tmp = ft_atoi(process->args);
			ft_free_struc(mini);
			free(mini);
			ft_free_process(process);
			free(process);
			exit(tmp % 256);
		}
	}	
}
