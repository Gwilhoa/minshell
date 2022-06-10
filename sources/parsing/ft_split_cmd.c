/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:20:53 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 08:47:03 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_cmd(char *str)
{
	int		nb;
	int		i;
	char	**split;
	char	*tmp;

	nb = ft_nbword(str);
	split = malloc(sizeof(char *) * nb + 1);
	nb = 0;
	i = 0;
	while (str[i] != 0)
	{
		i = ft_split_bash2(str, i, &tmp); //str la chaine de caractere a decouper, i la position de départ, tmp le resultat de la decoupe, retourne la position de fin de la decoupe
		nb++;
	}
	split[nb] = 0;
	return (split);
}

int	ft_wordstart(char *str, int i)
{
	if (i != 0)
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	return (i);
}

int	ft_nbword(char *str)
{
	int	i;
	int	q;
	int	q2;
	int	nb;

	q = 0;
	q2 = 0;
	i = 0;
	nb = 0;

	while (str[i])
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if (str[i] == ' ' && q == 0 && q2 == 0)
		{
			nb++;
			while (str[i] == ' ')
			i++;
		}
		else
			i++;
	}
	return (nb);
}
