/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:19:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/13 15:19:45 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/********    cd.c    ********/

void		ft_cd(t_process *process, t_minishell *mini);

/********    echo.c    ********/

void		ft_echo(t_process *process, t_minishell *shell);

/********    env.c    ********/

void		ft_env(char **env);

/********    exit.c    ********/

void		ft_exit(int args);

/********    export.c    ********/

int			ft_export(t_process *process, t_minishell *mini);

/********    pwd.c    ********/

void		ft_pwd(t_minishell *shell);

/********    unset.c    ********/

void		ft_unset(t_process *process, t_minishell *mini);

/********    execute_path.c    ********/

int			interpreting(t_minishell *mini, t_process *process);
int			cmd_bash(t_process *process, char **env);
int			path_execute_process(char *cmd, char *args[], char *env[]);
int			path_execute(char *path, char *args[], char *env[]);

/********    get_next_line.c    ********/

int			ft_search(char *str, int charset);
char		*ft_has_nl(char *ret, char *rest);
char		*ft_init(char *ret, char *str, int r);
int			reader(char **str, int fd);
char		*get_next_line(int fd);

/********    getallfile.c    ********/

char		*ft_getallfile(int fd);

/********    env_utils.c    ********/

char		*ft_getenv(char *key, char **env);
char		*ft_get_line_env(char *key, char **env);
void		ft_addenv(t_minishell *mini, char *str);
void		ft_change_env(char *key, char *newchar, t_minishell *mini);
void		ft_delenv(t_minishell *mini, char *key);

/********    main.c    ********/

int			main(int argc, char *argv[], char *envp[]);
void		executing(t_minishell *mini, t_process *process);
int			loop(t_minishell *mini);
void		incr_shlvl(t_minishell *mini);

/********    pipes.c    ********/

void		create_pipes(t_minishell *shell);

/********    signal.c    ********/

void		delsig(void);
void		get_signal(int sig);
void		useless_sig(int sig);

/********    create_cmd.c    ********/

void		ft_creat_command(t_minishell *main);
void		ft_send_file(t_process *process);
void		ft_send_outfile(t_process *process);
void		ft_send_infile(t_process *process);
void		ft_send_cmd(t_process *process);

/********    ft_lstadd_back2.c    ********/

void		ft_lstadd_back2(t_process **alst, t_process *new);

/********    ft_lstnew2.c    ********/

t_process	*ft_lstnew2(char **splitcmdi);

/********    parse_utils.c    ********/

int			ft_nbcmd(char *str);
int			ft_check_end(char *str);
int			ft_quotes(char *str) // a revoir;;
int			ft_simple_pipe(char *str);
char		*ft_envcmp(char *str, char **env);
void		ft_dollar(char **split, char **env);

/********    parsing_main.c    ********/

int			ft_parsing(t_minishell *main);

/********    cd.c    ********/

void		ft_cd(t_process *process, t_minishell *mini);

/********    echo.c    ********/

void		ft_echo(t_process *process, t_minishell *shell);

/********    env.c    ********/

void		ft_env(char **env);

/********    exit.c    ********/

void		ft_exit(int args);

/********    export.c    ********/

int			ft_export(t_process *process, t_minishell *mini);

/********    pwd.c    ********/

void		ft_pwd(t_minishell *shell);

/********    unset.c    ********/

void		ft_unset(t_process *process, t_minishell *mini);

/********    execute_path.c    ********/

int			interpreting(t_minishell *mini, t_process *process);
int			cmd_bash(t_process *process, char **env);
int			path_execute_process(char *cmd, char *args[], char *env[]);
int			path_execute(char *path, char *args[], char *env[]);

/********    get_next_line.c    ********/

int			ft_search(char *str, int charset);
char		*ft_has_nl(char *ret, char *rest);
char		*ft_init(char *ret, char *str, int r);
int			reader(char **str, int fd);
char		*get_next_line(int fd);

/********    getallfile.c    ********/

char		*ft_getallfile(int fd);

/********    env_utils.c    ********/

char		*ft_getenv(char *key, char **env);
char		*ft_get_line_env(char *key, char **env);
void		ft_addenv(t_minishell *mini, char *str);
void		ft_change_env(char *key, char *newchar, t_minishell *mini);
void		ft_delenv(t_minishell *mini, char *key);

/********    main.c    ********/

int			main(int argc, char *argv[], char *envp[]);
void		executing(t_minishell *mini, t_process *process);
int			loop(t_minishell *mini);
void		incr_shlvl(t_minishell *mini);

/********    pipes.c    ********/

void		create_pipes(t_minishell *shell);

/********    signal.c    ********/

void		delsig(void);
void		get_signal(int sig);
void		useless_sig(int sig);

/********    create_cmd.c    ********/

void		ft_creat_command(t_minishell *main);
void		ft_send_file(t_process *process);
void		ft_send_outfile(t_process *process);
void		ft_send_infile(t_process *process);
void		ft_send_cmd(t_process *process);

/********    ft_lstadd_back2.c    ********/

void		ft_lstadd_back2(t_process **alst, t_process *new);

/********    ft_lstnew2.c    ********/

t_process	*ft_lstnew2(char **splitcmdi);

/********    parse_utils.c    ********/

int			ft_nbcmd(char *str);
int			ft_check_end(char *str);
int			ft_quotes(char *str) // a revoir;;
int			ft_simple_pipe(char *str);
char		*ft_envcmp(char *str, char **env);
void		ft_dollar(char **split, char **env);

/********    parsing_main.c    ********/

int			ft_parsing(t_minishell *main);

#endif