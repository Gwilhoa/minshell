int		ft_search(char *str, int charset)
int		reader(char **str, int fd)
int		main(int argc, char *argv[], char *envp[]);
int		loop(t_minishell *mini);
int		isenddollar(int c);
int		ft_end_redirec(char *str, int i);
int		define_code(int c);
int		ft_nbword(char *str);
int		ft_count_chevron(char	*str);
int		ft_nbcmd(char *str);
int		ft_check_syntaxe(char *str);
int		ft_parsing(t_minishell *main);
char	*ft_has_nl(char *ret, char *rest)
char	*ft_init(char *ret, char *str, int r)
char	*get_next_line(int fd)
char	*ft_getenv(char *key, char **env);
char	*ft_get_line_env(char *key, char **env);
char	*ft_clean_str(char *str, int start, int end);
char	*ft_take_cmd(t_process *process);
char	**ft_split_bash(char *str);
char	**split_files(char	*str);
char	*readfd(int fd);
char	**ft_split_cmd(char *str, int nb);
void	ft_cd(t_process *process, t_minishell *mini);
void	ft_echo(t_process *process, t_minishell *shell);
void	ft_env(char **env);
void	ft_exit(t_minishell *mini, t_process *process);
void	ft_export(t_process *process, t_minishell *mini);
void	ft_pwd(void);
void	ft_unset(t_process *process, t_minishell *mini);
void	ft_changedup(t_minishell *mini, t_process *process);
void	searching_cmd(t_minishell *mini, t_process *process);
void	ft_bash(t_minishell *mini, t_process *process);
void	ft_searching_path(t_minishell *mini, t_process *process, char *path);
void	ft_execute(char *path, t_process *process, t_minishell *mini, \;
void	create_pipes(t_minishell *shell);
void	ft_setfilefd(t_minishell *mini);
void	ft_forks(t_minishell *mini, t_process *process);
void	inexec(t_minishell *mini);
void	absolute_failed(char str);
void	delsig(void);
void	get_signal(int sig);
void	ft_addenv(t_minishell *mini, char *str);
void	ft_change_env(char *key, char *newchar, t_minishell *mini);
void	ft_delenv(t_minishell *mini, char *key);
void	init_env(char **envp, t_minishell *mini);
void	incr_shlvl(t_minishell *mini);
void	ft_cleanfork(int outfd, int infd, t_minishell *mini);
void	ft_check_dollar(char **str, char **env, int isheredoc, int error);
void	ft_dollar_parse(int i, char **str, char **env, int error);
void	ft_clear_cmd(t_process *process);
void	ft_create_command(t_minishell *main);
void	addprocess(t_process **alst, t_process *new);
void	ft_split_cmd_args(t_process *process);
void	ft_clean_args(t_process *process);
void	ft_redirec(t_process *process, t_minishell *mini);
void	ft_setup(t_process *process, t_minishell *mini);
void	ft_outfile(t_process *process, int i);
void	ft_infile(t_process *process, int i);
void	ft_delquotes(char **str);
void	ft_search_heredoc(t_process *process, t_minishell *mini);
void	ft_in_hd(t_process *process, int i, t_minishell *mini);
void	ft_heredoc(t_process *process, char *str, t_minishell *mini);
void	fork_hd(int *piped, char *str, char **env);
#endif