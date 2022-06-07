/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/07 17:43:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *mini, t_process *process)
{
	int			i;

	(void) mini; //free structure
	i = 0;
	if (process == NULL || process->args == NULL)
	{
		ft_printf("exit\n");
		g_error = 0;
		exit(0);
	}
	while (process->args[i])
	{
		if (ft_isdigit(process->args[i]) == 0)
		{
			ft_printf("exit: %s: numeric argument required\n", process->args);
			exit(255);
		}
		else
			exit(ft_atoi(process->args) % 256);
	}
}
