/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:24:06 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/01 19:31:55 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	s = ft_strlen(s2);
	str = malloc((i + s) * sizeof(char) + 2);
	if (!str)
		return (0);
	i = 0;
	s = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[s])
	{
		str[i + s] = s2[s];
		s++;
	}
	str[i + s] = 0;
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 2);
	if (!str)
		return (0);
	i = 0;
	s = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[s])
	{
		str[i + s] = s2[s];
		s++;
	}
	str[i + s] = 0;
	free(s1);
	free(s2);
	return (str);
}

char	*ft_strjoin_space(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 3);
	if (!str)
		return (0);
	i = 0;
	s = -1;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = ' ';
	while (s2[++s])
		str[i + s] = s2[s];
	str[i + s] = 0;
	free(s1);
	free(s2);
	return (str);
}

char	*ft_strjoin_hd(char *s1, char *s2) 		// incomplet; -> quand tu envoies plusieurs ligne vide
{												// censé renvoi un retour a la ligne, et leaks surement
	char	*str;
	int		i;
	int		s;

	if (!s1 || !s2)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 3);
	if (!str)
		return (0);
	i = -1;
	s = -1;
	if (s1[i] != '\0')
	{	
		while (s1[++i])
			str[i] = s1[i];
		str[i] = '\n';
		i = i + 1;
	}
	while (s2[++s])
		str[i + s] = s2[s];
	str[i + s] = 0;
	free(s1);
	free(s2);
	return (str);
}
