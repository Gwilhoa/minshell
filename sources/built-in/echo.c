/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:54:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/22 13:31:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	flag_prompt(char *str)
{
	int	j;

	j = 1;
	if (str[0] != '-' || str[1] == 0)
		return (0);
	while (str[j] != 0)
	{
		if (str[j] != 'n')
			return (0);
		j++;
	}
	return (1);
}

void static	init_var(int *a, int *b, int *c)
{
	*a = 1;
	*b = 0;
	*c = 0;
}

void	ft_echo(t_process *process)
{
	char	**parse;
	int		i;
	int		isflag;
	int		back;

	init_var(&isflag, &i, &back);
	parse = ft_split_bash(process->args);
	while (parse && parse[i])
	{
		ft_delquotes(&parse[i]);
		if (isflag == 1)
		{
			isflag = flag_prompt(parse[i]);
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
