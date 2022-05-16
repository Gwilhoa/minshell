/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/05/14 08:36:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsing(t_minishell *main)
{
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