/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/05/13 15:12:56 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	ft_creat_command(t_minishell *main)
// {
// 	int	i;

// 	i = 0;
// 	main->process = malloc(sizeof(t_process) * (main->nbcmd));
// 	while (i < main->nbcmd)
// 	{
// 		main->process[i].fullcmd = ft_split(main->splitcmd[i], ' ');	// ne pas split avec des espaces;
// 		ft_send_file(&main->process[i]);
// 		i++;
// 	}
// 	return;
// } */

void	ft_creat_command(t_minishell *main)
{
	int			i;
	t_process	*tmp;

	i = 0;
	main->process = ft_lstnew2(ft_split(main->splitcmd[0], ' '));
	while (main->splitcmd[++i])
	{
		tmp = ft_lstnew2(ft_split(main->splitcmd[i], ' '));
		ft_lstadd_back2(&main->process, tmp);
	}
	tmp = main->process;
	while (tmp)
	{
		ft_send_file(tmp);
		tmp = tmp->next;
	}
}

void	ft_send_file(t_process *process)
{
	ft_send_outfile(process);
	ft_send_infile(process);
	ft_send_cmd(process);
}

void	ft_send_outfile(t_process *process)
{
	int	i;
	int	tmp;

	i = 0;
	while (process->fullcmd[i])
	{
		if (process->fullcmd[i][0] == '>' && process->fullcmd[i][1] != '>')
		{
			if (open(process->fullcmd[i + 1], O_RDONLY) == -1)
			{
				tmp = open(process->fullcmd[i + 1], O_CREAT, 0777);
				close(tmp);
				process->outfile = ft_strdup(process->fullcmd[i + 1]);
				return ;
			}
			else
				process->outfile = ft_strdup(process->fullcmd[i + 1]);
		}
		else if (process->fullcmd[i][0] == '>' && process->fullcmd[i][1] == '>')
		{
			process->outfile = ft_strdup(process->fullcmd[i + 1]);
			process->code = 1;
		}
		i++;
	}
}

void	ft_send_infile(t_process *process)
{
	int	i;

	i = 0;
	while (process->fullcmd[i])
	{
		if (process->fullcmd[i][0] == '<' && process->fullcmd[i][1] != '<')
		{
			if (open(process->fullcmd[i + 1], O_RDONLY) == -1)
			{
				process->infile = ft_strdup(process->fullcmd[i + 1]);
				return ;
			}
			else
				process->infile = ft_strdup(process->fullcmd[i + 1]);
		}
		else if (process->fullcmd[i][0] == '<' && process->fullcmd[i][1] == '<')
		{
			//fonction heredoc;
		}
		i++;
	}
}

void	ft_send_cmd(t_process *process)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (process->fullcmd[i])
	{
		if (process->fullcmd[i][0] == '<' || process->fullcmd[i][0] == '>')
			i++;
		else if (tmp == 0)
		{
			process->cmd = ft_strdup(process->fullcmd[i]);
			tmp = 1;
		}
		else if (tmp == 1)
			process->flags = ft_strdup(process->fullcmd[i]);
		i++;
	}
	return ;
}
