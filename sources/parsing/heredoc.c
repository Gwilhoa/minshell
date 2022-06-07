/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:51:56 by guyar             #+#    #+#             */
/*   Updated: 2022/06/07 16:16:53 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_search_heredoc(t_process *process)
{
	int	i;

	i = 0;
	while (process->all_redirec[i])
	{
		if (process->all_redirec[i][0] == '<' && \
			process->all_redirec[i][1] == '<')
			ft_in_hd(process, i);
		i++;
	}
}

void	ft_in_hd(t_process *process, int i)
{
	int	s;

	process->code = 2;
	s = process->code;
	while (process->all_redirec[i][s] == ' ')
		s++;
	if (process->all_redirec[i][s] == 0)
	{
		g_error = ERRO_SYNTAXE;
		return ;
	}
	if (process->hd_stop != NULL)
		free(process->hd_stop);
	process->hd_stop = ft_strdup(process->all_redirec[i] + s);
	if (process->infile != NULL)
	{
		free(process->infile);
		process->infile = NULL;
	}
	ft_heredoc(process, process->hd_stop);
}

void	ft_heredoc(t_process *process, char *str)
{
	char	*tmp;
	int		i;
	int		fd;
	int		piped[2];
	int		status;

	tmp = malloc(sizeof(char) * 1);
	tmp[0] = '\0';
	i = ft_strcmp(str, tmp);
	if (process->heredoc != NULL)
		free(process->heredoc);
	process->heredoc = malloc(sizeof(char) * 1);
	process->heredoc[0] = '\0';
	pipe(piped);
	if (pipe < 0)
		return ;
	fd = fork();
	g_error = INHEREDOC;
	if (fd == 0)
	{
		g_error = INHEREDOC_FORK;
		close(piped[0]);
		process->heredoc = malloc(1);
		process->heredoc[0] = '\0';
		while (i != 0)
		{
			tmp = readline("> ");
			i = ft_strcmp(str, tmp);
			if (i != 0)
			{
				ft_putstr_fd(tmp, piped[1]);
				ft_putstr_fd("\n", piped[1]);
			}
		}
		close(piped[1]);
		exit(0);
	}
	close(piped[1]);
	wait(&status);
	g_error = WEXITSTATUS(status);
	process->heredoc = readfd(piped[0]);
	close(piped[0]);
	g_error = 0;
	if (tmp != NULL)
		free(tmp);
	process->infd = 0;
}

char	*readfd(int fd)
{
	char	*ret;
	char	*reader;

	reader = get_next_line(fd);
	ret = malloc(1);
	ret[0] = '\0';
	while (reader != NULL)
	{
		ret = ft_strjoin_free(ret, reader);
		reader = get_next_line(fd);
	}
	return (ret);
}
