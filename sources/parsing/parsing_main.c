/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/08 21:33:17 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsing(t_minishell *main)
{
	if (main->str == NULL)
		return (-1);
	if (ft_check_end(main->str) == -1)
	{
		g_error = ERRO_SYNTAXE;
		return (-1);
	}
	if (ft_simple_pipe(main->str) == -1)
		return (-1);
	if (ft_quotes(main->str) == -1)
		return (-1);
	main->nbcmd = ft_nbcmd(main->str);
	main->splitcmd = ft_split(main->str, '|');
	ft_creat_command(main);
	return (0);
}
