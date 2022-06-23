/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:01:40 by guyar             #+#    #+#             */
/*   Updated: 2022/06/24 01:34:08 by guyar            ###   ########.fr       */
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
	if (process->fullcmd != NULL)
	{
		ft_free_matrix(process->fullcmd);
		free(process->fullcmd);
		process->fullcmd = NULL;
	}
	if (process->heredoc != NULL)
		free(process->heredoc);
	free(process);
}

void	ft_free_proccesses(t_process *process)
{
	t_process	*tmp;

	while (process != NULL)
	{
		tmp = process;
		process = process->next;
		ft_free_process(tmp);
	}
}

void	ft_free_struc(t_minishell *mini)
{
	ft_free_proccesses(mini->process);
	if (mini->env != NULL)
	{
		ft_free_matrix(mini->env);
		free(mini->env);
	}
	if (mini->splitcmd != NULL)
	{
		ft_free_matrix(mini->splitcmd);
		free(mini->splitcmd);
	}
}
