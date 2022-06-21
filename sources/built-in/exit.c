/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/21 17:56:48 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_minishell *mini, t_process *process)
{
	int			i;
	int 		tmp;

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
