/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:56:34 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/28 12:35:50 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned long int	ft_start(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (set[j] == s1[i])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

unsigned long int	ft_end(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;

	i = ft_strlen(s1);
	j = 0;
	while (set[j])
	{
		if (i > 0 && set[j] == s1[i - 1])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long int	end;
	unsigned long int	start;
	char				*ret_str;
	unsigned long int	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	ret_str = NULL;
	ret_str = ft_malloc_strtrim(ret_str, end, start);
	while (start < end)
	{
		ret_str[i++] = s1[start];
		start++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}

char	*ft_strtrim2(char *s1, char const *set)
{
	unsigned long int	end;
	unsigned long int	start;
	char				*ret_str;
	unsigned long int	i;

	i = 0;
	if (!s1 || !set)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	ret_str = NULL;
	ret_str = ft_malloc_strtrim(ret_str, end, start);
	while (start < end)
	{
		ret_str[i++] = s1[start];
		start++;
	}
	ret_str[i] = '\0';
	free(s1);
	return (ret_str);
}

char	*ft_malloc_strtrim(char *ret_str, int end, int start)
{
	if (start >= end)
	{
		ret_str = malloc(1);
		ret_str[0] = '\0';
	}
	else
	{
		ret_str = malloc ((end - start) + 1);
		if (!ret_str)
			return (NULL);
	}
	return (ret_str);
}
