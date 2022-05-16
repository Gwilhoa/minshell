/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:54:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/16 15:57:13 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_process *process, t_minishell *shell)
{
	char	**parse;
	int		i;

	if (process->args == NULL)
		return ;
	parse = ft_split(process->args, ' ');
	i = 0;
	while (parse[i] != 0)
	{
		ft_check_string(&parse[i], shell->env);
		if (i == 0)
			ft_printf("%s", parse[i]);
		else
			ft_printf(" %s", parse[i]);
		i++;
	}
	ft_printf("\n");
}
