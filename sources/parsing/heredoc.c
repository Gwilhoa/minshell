/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:51:56 by guyar             #+#    #+#             */
/*   Updated: 2022/07/04 17:21:56 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_search_heredoc(t_process *process, t_minishell *mini)
{
	int	i;

	i = 0;
	while (process->all_redirec[i])
	{
		if (process->all_redirec[i][0] == '<' && \
			process->all_redirec[i][1] == '<')
			ft_in_hd(process, i, mini);
		i++;
	}
}

void	ft_in_hd(t_process *process, int i, t_minishell *mini)
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
	process->hd_stop = ft_strdup(process->all_redirec[i] + s);
	if (process->infile != NULL)
	{
		free(process->infile);
		process->infile = NULL;
	}
	ft_heredoc(process, process->hd_stop, mini);
}

void	ft_heredoc(t_process *process, char *str, t_minishell *mini)
{
	int		fd;
	int		piped[2];
	int		status;

	(void) mini;
	pipe(piped);
	if (pipe < 0)
		return ;
	fd = fork();
	g_error = INHEREDOC;
	if (fd == 0)
		fork_hd(piped, str);
	close(piped[1]);
	wait(&status);
	free(process->hd_stop);
	g_error = WEXITSTATUS(status);
	process->infd = piped[0];
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

void	fork_hd(int *piped, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	g_error = INHEREDOC_FORK;
	close(piped[0]);
	while (i != 0)
	{
		tmp = readline("> ");
		if (tmp == NULL)
			break ;
		i = ft_strcmp(str, tmp);
		if (i != 0)
		{
			ft_putstr_fd(tmp, piped[1]);
			ft_putstr_fd("\n", piped[1]);
			free(tmp);
		}
	}
	close(piped[1]);
	exit(0);
}
