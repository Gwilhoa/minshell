/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:06:31 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/09 11:48:00 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	STRING			d;
	const STRING	s;

	i = 0;
	if (!dest && !src)
		return (dest);
	s = (STRING)src;
	d = (STRING)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
