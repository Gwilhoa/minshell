/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:10:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/04 09:38:14 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_empty_env(t_minishell *mini)
{
	char	*pwd;
	char	*temp;

	pwd = getcwd(NULL, 10);
	temp = ft_getenv("PWD", mini->env);
	if (temp == NULL)
		ft_addenv(mini, ft_strjoin("PWD=", pwd));
	else
		free(temp);
	temp = ft_getenv("SHLVL", mini->env);
	if (temp == NULL)
		ft_addenv(mini, "SHLVL=1");
	else
	{
		free(temp);
		incr_shlvl(mini);
	}
	free(pwd);
}

void	init_env(char **envp, t_minishell *mini)
{
	int		i;
	char	*temp;

	i = -1;
	if (ft_matrix_size((const char **)envp) == 0)
	{
		mini->env = malloc(sizeof(char *));
		mini->env[0] = 0;
	}
	else
		mini->env = ft_matrix_dup(envp);
	temp = ft_get_line_env("OLDPWD", mini->env);
	if (temp == NULL)
		ft_addenv(mini, "OLDPWD");
	while (mini->env[++i] != 0)
	{
		if (ft_strncmp(mini->env[i], "OLDPWD", 6) == 0)
		{
			free(mini->env[i]);
			mini->env[i] = ft_strdup("OLDPWD");
		}
	}
	init_empty_env(mini);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell	mini;

	(void) argc;
	(void) argv;
	signal(SIGINT, get_signal);
	signal(SIGQUIT, get_signal);
	g_error = 0;
	mini.default_outfd = dup(1);
	mini.default_infd = dup(0);
	init_env(envp, &mini);
	mini.process = NULL;
	loop(&mini);
	return (0);
}

int	ft_error_parse(int i, char **str)
{
	char	*ret;
	char	*start;
	char	*end;
	char	*change;
	int		j;

	ret = ft_strdup(*str);
	free(*str);
	start = ft_substr(ret, 0, i);
	j = i + 2;
	change = ft_substr(ret, i + 1, 1);
	change = ft_dollarenv(change, NULL, 1);
	i = ft_dollar_parse_i(change, start);
	end = ft_substr(ret, j, ft_strlen(ret + j));
	free(ret);
	*str = ft_dollar_parse_ret(start, end, change);
	ft_clean_str(str);
	return (i);
}

void ft_check_error(char **line)
{
	int		i;
	char	*ret;
	int		doublequote;
	int		singlequote;

	doublequote = 0;
	singlequote = 0;
	ret = ft_strdup(*line);
	free(*line);
	i = 0;
	while (ret && ret[i] != 0)
	{
		if (singlequote == 0 && ret[i] == '\"')
			doublequote = -doublequote + 1;
		else if (doublequote == 0 && ret[i] == '\'')
			singlequote = -singlequote + 1;
		else if (ret[i] == '$' && singlequote == 0)
		{
			if (ret[i + 1] != 0 && ft_isspace(ret[i + 1]) != 1 && \
				ret[i + 1] == '?')
				i = ft_error_parse(i, &ret) - 1;
		}
		i++;
	}
	*line = ret;
}

int	loop(t_minishell *mini)
{
	char		*line;

	while (1)
	{
		line = readline("minshell >> ");
		if (line == NULL)
			ft_exit(mini, NULL);
		if (line[0] != 0)
		{
			add_history(line);
			if (line != NULL)
			{
				ft_check_error(&line);
				g_error = 0;
				if (ft_parsing(mini, line) == 0 && g_error == 0)
					inexec(mini);
				if (mini->process != NULL)
					ft_free_proccesses(mini->process);
				mini->process = NULL;
			}
		}
		free(line);
	}
}

void	incr_shlvl(t_minishell *mini)
{
	char		*temp;
	char		*ret;

	temp = ft_getenv("SHLVL", mini->env);
	ret = ft_itoa(ft_atoi(temp) + 1);
	ft_change_env("SHLVL", ret, mini);
	free(ret);
	free(temp);
}
