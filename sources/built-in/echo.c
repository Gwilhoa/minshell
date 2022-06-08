/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:54:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/08 15:25:51 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_process *process, t_minishell *shell)
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
	parse = ft_split(process->args, ' ');
	i = 0;
	while (parse[i] != 0)
	{
		ft_check_dollar(&parse[i], shell->env, 0);
		if (isflag == 1)
		{
			j = 1;
			if (parse[i][0] != '-')
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
