/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:27:23 by guyar             #+#    #+#             */
/*   Updated: 2022/05/25 10:51:10 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setup(t_process *process)
{
	int	i;
	int	s;
	int	fd;

	i = 0;
	while (process->all_redirec[i] != 0)
	{
		if (process->all_redirec[i][0] == '>')
		{
			if (process->all_redirec[i][1] != '>')
				process->code = 1;
			else
				process->code = 2;
			s = process->code;
			while (process->all_redirec[i][s] == ' ')
				s++;
			if (process->all_redirec[i][s] == 0)
			{
				g_error = ERRO_SYNTAXE;
				return ;
			}
			process->outfile = process->all_redirec[i] + s;
			fd = open(process->outfile, O_CREAT, 0777);
			if (fd < 0)
				return ;
			close(fd);
		}
		if (process->all_redirec[i][0] == '<')
		{
			process->infile = process->all_redirec[i] + 1;
			fd = open(process->all_redirec[i] + 1, O_RDONLY);
			if (fd < 0)
				return ;
			close(fd);
		}
		i++;
	}
}

void	ft_redirec(t_process *process)
{
	process->all_redirec = split_files(process->redirec);
	if (process->all_redirec == 0)
		return ;
	ft_setup(process);
}
