/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:54:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/11 19:04:20 by gchatain         ###   ########lyon.fr   */
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
	ft_check_dollar(&process->args, shell->env, 0);
	parse = ft_split_bash(process->args);
	i = 0;
	while (parse && parse[i])
	{
		ft_delquotes(&parse[i]);
		i++;
	}
	if (g_error == -1)
	{
		ft_putstr_fd("error : bad syntax\n", 2);
		exit(1);
	}
	i = 0;
	while (parse[i] != 0)
	{
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
