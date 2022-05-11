/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellG.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:58 by guyar             #+#    #+#             */
/*   Updated: 2022/05/11 22:09:03 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLG_H
# define MINISHELLG_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
	

*/
typedef struct s_process
{
	char		*cmd;	
	char		*flags;
	char		*args;	// je ne m'en sert pas;

	char	**fullcmd;
	char	*infile;
	char 	*outfile;
	int 	infd;
	int		outfd;
	int		code;
	struct s_process *next;
}	t_process;

typedef struct s_minishell
{
	t_process	*process;
	char		**env;
	char		**argv;
	char		*str;
	char		**splitcmd;
	int			nbcmd;
	int			default_fd;
}	t_minishell;

void ft_creat_command(t_minishell *main);
void ft_send_file(t_process *process);
void ft_send_infile(t_process *process);
void ft_send_outfile(t_process *process);
void ft_send_cmd(t_process *process);

#endif