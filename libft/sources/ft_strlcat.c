/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:35:36 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/02 14:54:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned long int	i;
	unsigned long int	j;
	unsigned long int	k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	k = j;
	if (size == 0 || i > size)
		return (size + j);
	if (!src)
		return (i);
	j = 0;
	while (src[j] && (i + j < size - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + k);
}
