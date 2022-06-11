/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/11 17:19:07 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_creat_command(t_minishell *main)
{
	int			i;
	t_process	*tmp;

	i = 0;
	main->process = ft_init_process(main->splitcmd[i]);
	while (main->splitcmd[++i])
	{
		tmp = ft_init_process(main->splitcmd[i]);
		addprocess(&main->process, tmp);
	}
	tmp = main->process;
	while (tmp)
	{
		ft_clear_cmd(tmp);
		ft_redirec(tmp, main);
		ft_cmd_args(tmp);
		ft_check_dollar(&tmp->cmd, main->env, 0);
		ft_delquotes(&tmp->cmd);
		if (tmp->args != NULL)
			ft_check_dollar(&tmp->args, main->env, 0);
		tmp = tmp->next;
	}
}
