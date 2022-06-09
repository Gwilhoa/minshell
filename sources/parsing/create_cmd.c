/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/09 20:23:04 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_creat_command(t_minishell *main)
{
	int			i;
	t_process	*tmp;

	i = 0;
	main->process = ft_lstnew2(main->splitcmd[i]);
	while (main->splitcmd[++i])
	{
		tmp = ft_lstnew2(main->splitcmd[i]);
		ft_lstadd_back2(&main->process, tmp);
	}
	tmp = main->process;
	while (tmp)
	{
		ft_clear_cmd(tmp);
		ft_redirec(tmp, main);
		ft_split_cmd(tmp->cmd);
		// dprintf(2, "cmd = '%s'\n", tmp->cmd);
		exit(EXIT_SUCCESS);
		ft_cmd_args(tmp);
		dprintf(2, "outfile = '%s'\n", tmp->outfile);
		dprintf(2, "infile = '%s'\n", tmp->infile);
		dprintf(2, "args = '%s'\n", tmp->args);
		dprintf(2, "heredoc = '%s'\n", tmp->heredoc);
		tmp = tmp->next;
	}
}
