/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:22 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/11 13:54:46 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipes(t_minishell *shell)
{
	int			i;
	t_process	*process;

	i = 0;
	process = shell->process;
	while (process->next != NULL)
	{
		if (pipe(process->process_nb + 2 * i) < 0)
			ft_perror("fail , lets free", 1);
		i++;
		process->next;
	}
}
