/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:36:51 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/09 11:45:58 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	STRING			v;

	i = 0;
	v = (STRING) s;
	while (i < n)
	{
		v[i] = 0;
		i++;
	}
	return (s);
}
