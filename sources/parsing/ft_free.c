/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:01:40 by guyar             #+#    #+#             */
/*   Updated: 2022/06/18 20:40:35 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_process(t_process *process)
{
	

	if (process->cmd != NULL)
		free(process->cmd);
	if (process->args != NULL)
		free(process->args);
	if (process->redirec != NULL)
		free(process->redirec);
	if (process->all_redirec != NULL)
	{
		ft_free_matrix(process->all_redirec);
		free(process->all_redirec);
		process->all_redirec = NULL;
	}
	// if (process->outfile != NULL)		// bug ici;
		// free(process->outfile);
	// if (process->infile != NULL)
	// 	free(process->infile);
	if (process->fullcmd != NULL)
	{
		ft_free_matrix(process->fullcmd);
		free(process->fullcmd);
		process->fullcmd = NULL;
	}
	if (process->hd_stop != NULL)		// bug ici;
		free(process->hd_stop);
	if (process->heredoc != NULL)
		free(process->heredoc);
}