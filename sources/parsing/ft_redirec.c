/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:27:23 by guyar             #+#    #+#             */
/*   Updated: 2022/06/01 17:45:11 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setup(t_process *process)
{
	int	i;

	i = 0;
	while (process->all_redirec[i] != 0)
	{
		if (process->all_redirec[i][0] == '>')
		{
			ft_outfile(process, i);
			if (g_error != 0)
				return ;
		}
		else if (process->all_redirec[i][0] == '<' &&
				process->all_redirec[i][1] != '<')
		{
			ft_infile(process, i);
			if (g_error != 0)
				return ;
		}
		i++;
	}
}

int	define_code(int c)
{
	if (c == '>')
		return (2);
	return (1);
}

void	ft_outfile(t_process *process, int i)
{
	int	s;
	int	fd;

	process->code = define_code(process->all_redirec[i][1]);
	s = process->code;
	while (ft_isspace(process->all_redirec[i][s]) == 1)
		s++;
	if (process->all_redirec[i][s] == 0)
	{
		g_error = ERRO_SYNTAXE;
		ft_printf("minshell >>> syntax error near unexpected token\n");
		return ;
	}
	process->outfile = process->all_redirec[i] + s;
	if (process->code == 1)
		fd = open(process->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(process->outfile, O_CREAT, 0644);
	if (fd < 0)
	{
		perror(process->outfile);
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
	while (ft_isspace(process->all_redirec[i][s]) == 1)
		s++;
	if (process->all_redirec[i][s] == 0)
	{
		g_error = ERRO_SYNTAXE;
		ft_printf("minshell >>> syntax error near unexpected token\n");
		return ;
	}
	process->infile = process->all_redirec[i] + s;
	fd = open(process->infile, O_RDONLY);
	if (fd < 0)
	{
		perror(process->infile);
		g_error = 1;
		return ;
	}
	close(fd);
}

void	ft_redirec(t_process *process)
{
	process->all_redirec = split_files(process->redirec);
	if (process->all_redirec == 0)
		return ;
	ft_search_heredoc(process);
	ft_setup(process);
}
