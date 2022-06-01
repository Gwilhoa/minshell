/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:27:23 by guyar             #+#    #+#             */
/*   Updated: 2022/06/01 10:50:41 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setup(t_process *process)
{
	int	i;

	i = 0;
	while (process->all_redirec[i] != 0)
	{
		ft_printf(" redirect en cours : '%s'\n", process->all_redirec[i]);
		if (process->all_redirec[i][0] == '>')
		{
			ft_outfile(process, i);
			if (g_error != 0)
				return ;
		}
		else if (process->all_redirec[i][0] == '<')
		{
			ft_infile(process, i);
			if (g_error != 0)
				return ;
		}
		i++;
	}
}

void	ft_outfile(t_process *process, int i)
{
	int	s;
	int	fd;

	process->code = 1;
	if (process->all_redirec[i][1] == '>')
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
	if (process->code == 1)
		fd = open(process->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(process->outfile, O_CREAT, 0644);
	if (fd < 0)
	{
		g_error = 1;
		return ;
	}
	close(fd);
}

void	ft_infile(t_process *process, int i)
{
	int	s;
	int	fd;

	s = 1;
	while (process->all_redirec[i][s] == ' ')
		s++;
	if (process->all_redirec[i][s] == 0)
	{
		g_error = ERRO_SYNTAXE;
		return ;
	}
	process->infile = process->all_redirec[i] + s;
	fd = open(process->infile, O_RDONLY);
	if (fd < 0)
	{
		g_error = 1;
		return ;
	}
	close(fd);
}

void	ft_redirec(t_process *process)
{
	ft_printf("%s\n", process->redirec);
	process->all_redirec = split_files(process->redirec);
	if (process->all_redirec == 0)
		return ;
	ft_setup(process);
}
