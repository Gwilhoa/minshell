/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:05:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/24 16:33:59 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <termios.h>
# include "color.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define INEXECVE -205
# define CMDNOTFOUND 127
# define ERRO_SYNTAXE 258
# define SIGC 130
# define SIGD -3

int							g_error;
typedef struct s_process	t_process;

typedef struct s_process
{
	int			code;
	int			process_nb;
	t_process	*next;
	char		*cmd;
	char		*args;
	char		*redirec;
	char		**all_redirec;
	char		*outfile;
	char		*infile;
	char		**fullcmd;
	int			outfd;
	int			infd;
}	t_process;

typedef struct s_minishell
{
	t_process	*process;
	char		**env;
	int			default_outfd;
	int			default_infd;
	char		*argv;
	char		*str;
	char		**splitcmd;
	int			nbcmd;
}	t_minishell;

int			ft_export(t_process *process, t_minishell *mini);
int			cmd_bash(t_process *process, char **env);
int			path_execute_process(char *cmd, char *args[], char *env[]);
int			path_execute(char *path, char *args[], char *env[]);
int			main(int argc, char *argv[], char *envp[]);
int			loop(t_minishell *mini);
int			ft_clean_till(char *str, int i);
int			ft_count_chevron(char	*str);
int			ft_nbcmd(char *str);
int			ft_check_end(char *str);
int			ft_quotes(char *str);
int			ft_simple_pipe(char *str);
int			ft_parsing(t_minishell *main);
char		*ft_getenv(char *key, char **env);
char		*ft_get_line_env(char *key, char **env);
char		*ft_tilde_parse(int i, char *ret, char **env);
char		*ft_dollar_parse(int i, char *ret, char **env);
char		*ft_getchange(int i, char *ret, char **env);
char		*ft_clean_str(char *str, int start, int end);
char		*ft_take_cmd(t_process *process);
char		**split_files(char	*str);
char		*ft_envcmp(char *str, char **env);
void		ft_cd(t_process *process, t_minishell *mini);
void		ft_echo(t_process *process, t_minishell *shell);
void		ft_env(char **env);
void		ft_exit(int args);
void		ft_pwd(t_minishell *shell);
void		ft_unset(t_process *process, t_minishell *mini);
void		interpreting(t_minishell *mini, t_process *process);
void		ft_addenv(t_minishell *mini, char *str);
void		ft_change_env(char *key, char *newchar, t_minishell *mini);
void		ft_delenv(t_minishell *mini, char *key);
void		executing(t_minishell *mini, t_process *process);
void		incr_shlvl(t_minishell *mini);
void		create_pipes(t_minishell *shell);
void		delsig(void);
void		get_signal(int sig);
void		useless_sig(int sig);
void		ft_check_string(char **str, char **env);
void		ft_clear_cmd(t_process *process);
void		ft_creat_command(t_minishell *main);
void		ft_cmd_args(t_process *process);
void		ft_take_args(t_process *process, char	*tmp);
void		ft_lstadd_back2(t_process **alst, t_process *new);
void		ft_setup(t_process *process);
void		ft_redirec(t_process *process);
void		ft_send_file(t_process *process);
void		ft_send_outfile(t_process *process);
void		ft_send_infile(t_process *process);
void		ft_send_cmd(t_process *process);
void		ft_send_args(t_process *process);
t_process	*ft_lstnew2(char *clean_cmd);

#endif