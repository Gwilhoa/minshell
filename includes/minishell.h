/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:05:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/01 11:32:33 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define FAILED 1
# define SUCCESS 0
# define INEXECVE -205
# define CMDNOTFOUND 127
# define ERRO_SYNTAXE 258
# define SIGC 130
# define SIGD -3
# define INHEREDOC -2
# define INHEREDOC_FORK -2000
# define INFORK -500

int							g_error;
typedef struct s_process	t_process;
typedef struct s_minishell	t_minishell;

struct s_process
{
	int			pid;

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
	char		*hd_stop;
};

typedef struct s_split
{
	char	**ret;
	int		nb;
	int		i;
	int		p;
	int		q[2];
}				t_split;
typedef struct s_minishell
{
	t_process	*process;
	char		**env;
	int			default_outfd;
	int			default_infd;
	char		**splitcmd;
	int			nbcmd;
}	t_minishell;

int			flag_prompt(char *str);
int			verif_args_env(char *str);
int			main(int argc, char *argv[], char *envp[]);
int			loop(t_minishell *mini);
int			isenddollar(int c);
int			ft_dollar_parse(int i, char **str, char **env);
int			ft_end_redirec(char *str, int i);
int			define_code(int c);
int			ft_nbword(char *str);
int			ft_count_chevron(char	*str);
int			ft_nbcmd(char *str);
int			ft_check_syntaxe(char *str);
int			ft_parsing(t_minishell *main, char *line);
char		*ft_getenv(char *key, char **env);
char		*ft_get_line_env(char *key, char **env);
char		*ft_dollarenv(char *str, char **env, int error);
char		*ft_dollar_parse_ret(char *start, char *end, char *change);
char		*ft_take_cmd(t_process *process);
char		**ft_split_bash(char *str);
char		**split_files(char	*str);
char		*ft_cutfile(char *str, int start);
char		*readfd(int fd);
char		**ft_split_cmd(char *str, int nb);
void		error_path(char *args);
void		ft_cd(t_process *process, t_minishell *mini);
void		ft_echo(t_process *process);
void		ft_env(char **env);
void		ft_check_error(char **line);
void		ft_exit(t_minishell *mini, t_process *process);
void		ft_exit_code(t_minishell *mini, t_process *process, int tmp);
void		ft_export(t_process *process, t_minishell *mini);
void		ft_export_loop(char **args, char **arg, char *env, \
				t_minishell *mini);
void		ft_pwd(char **env);
void		ft_unset(t_process *process, t_minishell *mini);
void		searching_cmd(t_minishell *mini, t_process *process);
void		ft_changedup(t_minishell *mini, t_process *process);
void		ft_bash(t_minishell *mini, t_process *process);
void		ft_searching_path(t_minishell *mini, \
				t_process *process, char *path);
void		ft_execute(char *path, t_process *process, t_minishell *mini, \
				int i);
void		create_pipes(t_minishell *shell);
void		ft_setfilefd(t_minishell *mini);
void		ft_cleanfork(int outfd, int infd, t_minishell *mini);
void		ft_forks(t_minishell *mini, t_process *process);
void		inexec(t_minishell *mini);
void		absolute_failed(char *str);
void		delsig(void);
void		get_signal(int sig);
void		sigfork(int sig);
void		ft_addenv(t_minishell *mini, char *str);
void		ft_change_env(char *key, char *newchar, t_minishell *mini);
void		ft_delenv(t_minishell *mini, char *key);
void		init_empty_env(t_minishell *mini);
void		init_env(char **envp, t_minishell *mini);
void		incr_shlvl(t_minishell *mini);
void		ft_check_dollar(char **str, char **env, int isheredoc);
void		ft_clear_cmd(t_process *process);
void		remove_file(char **str, int start, int end);
void		ft_create_command(t_minishell *main);
void		ft_create_command_loop(t_process *tmp, t_minishell *main, \
				char *home);
void		addprocess(t_process **alst, t_process *new);
void		ft_split_cmd_args(t_process *process, char *home);
void		ft_clean_args(t_process *process, char *home);
void		ft_clean_str(char **str);
void		ft_free_process(t_process *process);
void		ft_free_proccesses(t_process *process);
void		ft_free_struc(t_minishell *mini);
void		ft_redirec(t_process *process, t_minishell *mini);
void		ft_setup(t_process *process, t_minishell *mini);
void		ft_outfile(t_process *process, int i);
void		ft_infile(t_process *process, int i);
void		ft_split_bash_2(t_split *split_struct, char *str);
void		ft_delquotes(char **str);
void		ft_search_heredoc(t_process *process, t_minishell *mini);
void		ft_in_hd(t_process *process, int i, t_minishell *mini);
void		ft_heredoc(t_process *process, char *str, t_minishell *mini);
void		fork_hd(int *piped, char *str);
t_process	*ft_init_process(char *str);
t_process	*process_executing(t_minishell *mini, t_process *process);
int			ft_dollar_parse_i(char *change, char *start);
#endif