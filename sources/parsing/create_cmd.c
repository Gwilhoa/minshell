/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/01 12:20:22 by gchatain         ###   ########lyon.fr   */
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
		ft_redirec(tmp);
		ft_cmd_args(tmp);
		tmp = tmp->next;
	}
}
