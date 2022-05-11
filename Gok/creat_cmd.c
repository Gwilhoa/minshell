/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/05/11 22:08:04 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishellG.h"

void ft_creat_command(t_minishell *main)
{
	int i;

	i = 0;
	main->process = malloc(sizeof(t_process) * (main->nbcmd));
	while (i < main->nbcmd)
	{
		main->process[i].fullcmd = ft_split(main->splitcmd[i], ' ');	// ne pas split avec des espaces;
		ft_send_file(&main->process[i]);
		dprintf(2, "cmd = %s\n", main->process[i].cmd);
		dprintf(2, "infile = %s\n", main->process[i].outfile);
		dprintf(2, "code = %d\n", main->process[i].code);
		i++;
	}
	return;
}


void ft_send_file(t_process *process)
{
	ft_send_outfile(process);
	ft_send_infile(process);
	ft_send_cmd(process);
}


void ft_send_outfile(t_process *process)
{
	int i;

	i = 0;
	while (process->fullcmd[i])
	{
		if (process->fullcmd[i][0] == '>' && process->fullcmd[i][1] != '>')
		{
			if (open(process->fullcmd[i + 1], O_RDONLY) == -1)
			{
				open(process->fullcmd[i + 1], O_CREAT, 0777);  // où vaut-il mieux le creer ?;
				process->outfile = ft_strdup(process->fullcmd[i + 1]);
				return;
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
		

void ft_send_infile(t_process *process)
{
	int i;

	i = 0;
	while (process->fullcmd[i])
	{
		if (process->fullcmd[i][0] == '<' && process->fullcmd[i][1] != '<')
		{
			if (open(process->fullcmd[i + 1], O_RDONLY) == -1)
			{
				process->infile = ft_strdup(process->fullcmd[i + 1]);
				return;
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

void ft_send_cmd(t_process *process)
{
	int i;
	int tmp;
	
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
			process->flags =ft_strdup(process->fullcmd[i]);
		i++;
	}
	return;
}
