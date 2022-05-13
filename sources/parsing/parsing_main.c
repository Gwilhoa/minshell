/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/05/13 19:05:32 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsing(t_minishell *main)
{
	int	i;

	i = 0;
	if (main->str == NULL)
		return (-1);
	if (ft_check_end(main->str) == -1)
		return (-1);
	if (ft_simple_pipe(main->str) == -1)
		return (-1);
	main->nbcmd = ft_nbcmd(main->str);
	main->splitcmd = ft_split(main->str, '|');	//regarder si le pipe
	ft_dollar(main->splitcmd, main->env);
	ft_creat_command(main);
	
	return (0);
}