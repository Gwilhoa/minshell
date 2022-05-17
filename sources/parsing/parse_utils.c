/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:26:20 by guyar             #+#    #+#             */
/*   Updated: 2022/05/17 09:28:11 by gchatain         ###   ########lyon.fr   */
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
	while (str[i] == ' ') // white space
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
				return (env[i] + (ft_strlen(str) + 1)); // return env;
		}
		j = 0;
		i++;
	}
	return (0);
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