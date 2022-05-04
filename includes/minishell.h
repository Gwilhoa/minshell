/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:05:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/04 11:09:42 by gchatain         ###   ########lyon.fr   */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	g_error;

# define INEXECVE -205
# define SIGC -301
# define SIGD -302

int		cmd_bash(char **args, char *env[]);
int		path_execute_process(char *cmd, char *args[], char *env[]);
int		path_execute(char *path, char *cmd, char *args[], char *env[]);
int		main(int argc, char *argv[], char *envp[]);
int		loop(char *envp[]);
int		interpreting(char **args, char *env[]);
int		ft_isredirecting(const STRING str);
char	*ft_echo(char **args);
char	*ft_getenv(char *key, char **env);
void	ft_cd(char *args, char **env);
void	ft_change_env(char *key, char *newchar, char **env);
void	ft_exit(int args);
void	ft_pwd(char **env);
void	get_signal(int sig);
void	ft_addenv(char *str, char **env);

#endif