/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:26:20 by guyar             #+#    #+#             */
/*   Updated: 2022/05/16 14:22:53 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_nbcmd(char *str)
{
	int	i;
	int	nb;

	nb = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			nb++;
		i++;
	}
	return (nb);
}

int	ft_check_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ')	// white space
		i--;
	if (str[i] == '|' || str[i] == '[' || str[i] == ']')
		return (-1);
	return (0);
}

int	ft_quotes(char *str) // a revoir;
{
	int	i;
	int	cmpt;
	int	cmpt2;

	i = 0;
	cmpt = 0;
	cmpt2 = 0;
	while (str[i])
	{
		if (str[i] == '"')
			cmpt++;
		if (str[i] == '\'')
			cmpt++;
		if (cmpt == 2)
		{
			cmpt = 0;
			if (cmpt2 == 1)
				cmpt2 = 0;
		}
		i++;
	}
	return (0);
}

int	ft_simple_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '|') && (str[i + 1] == '|')
			&& (str[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_envcmp(char *str, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j] == str[j])
		{
			j++;
			if (str[j] == 0)
				return (env[i] + (ft_strlen(str) + 1));	// return env;
		}
		j = 0;
		i++;
	}
	return (0);
}

// replace, from the $, and put the equivalence of the variable; 

void	ft_check_string(char **str, char **env)
{
	int	i;
	int	f;
	char	*start;
	char	*change;
	char	*end;
	char	*ret;

	ret = *str;
	i = 0;
	while (ret[i] != 0)
	{
		if (ret[i] == '~')
		{
			if (i != 0)
				start = ft_substr(ret, 0, i);
			else
			{
				start = malloc(1);
				start[0] = 0;
			}
			change = ft_getenv("HOME", env);
			end = ft_substr(ret, i +1, ft_strlen(*str));
			ret = ft_strjoin(ft_strjoin(start, change), end);
		}
		if (ret[i] == '$')
		{
			if (i != 0)
				start = ft_substr(ret, 0, i);
			else
			{
				start = malloc(1);
				start[0] = 0;
			}
			f = i;
			while (ret[i] != ' ' && ret[i] != 0)
			{
				i++;
			}
			change = ft_substr(ret, f + 1, i);
			change = ft_getenv(change, env);
			if (change == NULL)
			{
				change = malloc(1);
				change[0] = 0;
			}
			end = ft_substr(ret, i, ft_strlen(*str));
			ret = ft_strjoin(ft_strjoin(start, change), end);
		}
		i++;
	}
	*str = ret;
}




/* 
	to do ;
	-regarder si le pipe n'est pas entre guillemet, sinon c'est pas un pipe
	-read line pour lire dans le terminal;

	-heredoc
		avec d_strdup, on le met dans un coin caché
		creer un nombre de airdoc en fonction du nombre de heredoc qu'il a rencontré;
	- ne pas split la commande avec des espaces
	
*/