/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:05:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/09 15:04:40 by gchatain         ###   ########lyon.fr   */
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

# define INEXECVE -205
# define SIGC -301
# define SIGD -302

typedef struct s_process	t_process;

int							g_error;

typedef struct s_process
{
	t_process	*next;
	char		*cmd;
	char		*args;
	char		*flags;
	int			outfd;
	int			infd;
}	t_process;

typedef struct s_minishell
{
	t_process	*process;
	char		**env;
	int			default_fd;
}	t_minishell;

int		interpreting(t_minishell *mini, t_process *process);
int		cmd_bash(t_process *process, char **env);
int		path_execute_process(char *cmd, char *args[], char *env[]);
int		path_execute(char *path, char *cmd, char *args[], char *env[]);
int		ft_export(t_process *process, t_minishell *mini);
int		main(int argc, char *argv[], char *envp[]);
int		loop(t_minishell *mini);
char	*ft_getenv(char *key, char **env);
char	*ft_get_line_env(char *key, char **env);
void	ft_cd(t_process *process, t_minishell *mini);
void	ft_echo(t_process *process, t_minishell *shell);
void	ft_env(char **env);
void	ft_addenv(char *str, char **env);
void	ft_change_env(char *key, char *newchar, char **env);
void	ft_delenv(t_minishell *mini, char	*key);
void	ft_exit(int args);
void	incr_shlvl(t_minishell *mini);
void	new_process(t_minishell *mini, char *name, char *args);
void	ft_pwd(t_minishell *shell);
void	delsig(void);
void	get_signal(int sig);
void	useless_sig(int sig);

#endif