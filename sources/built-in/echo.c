/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:54:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/13 14:42:41 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_process *process)
{
	char	**parse;
	int		i;
	int		j;
	int		isflag;
	int		back;

	isflag = 1;
	back = 0;
	if (process->args == NULL)
		exit(0);
	parse = ft_split_bash(process->args);
	i = 0;
	while (parse && parse[i])
	{
		ft_delquotes(&parse[i]);
		j = 0;
		if (isflag == 1)
		{
			j = 1;
			if (parse[i][0] != '-' || parse[i][1] == 0)
				isflag = 0;
			while (parse[i][j] != 0)
			{
				if (parse[i][j] != 'n')
					isflag = 0;
				j++;
			}
			if (isflag == 1)
				back = 1;
		}
		else
			ft_printf(" ");
		if (isflag == 0)
			ft_printf("%s", parse[i]);
		i++;
	}
	if (back == 0)
		ft_printf("\n");
	exit(0);
}
