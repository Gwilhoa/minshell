/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:05:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/13 14:54:50 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <termios.h>
# include "color.h"
# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

void	ft_exit();
int		main(int argc, char *argv[], char *envp[]);
int		loop(char *envp[]);
int		getcmd(char **args, char *envp[]);
int		ft_isredirecting(const STRING str);
int		cmd_bash(char **args, char *envp[]);
char	*ft_echo(char **args);
char	*ft_pwd(void);
void	get_signal(int sig);
int		path_execute(char *cmd, char *args[], char *env[]);

#endif
