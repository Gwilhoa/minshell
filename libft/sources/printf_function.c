/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:17:56 by gchatain          #+#    #+#             */
/*   Updated: 2022/02/02 14:54:39 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int nb, int fd)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = ft_putunsigned(nb / 10, fd);
		i = i + ft_putunsigned(nb % 10, fd);
	}
	else
	{
		i = i + ft_putchar_fd(nb + 48, fd);
	}
	return (i);
}

int	ft_putchangebase(unsigned int nbr, const char *base, int fd)
{
	int	i;

	i = 0;
	if (nbr > (unsigned int)ft_strlen(base) - 1)
	{
		i = ft_putchangebase(nbr / ft_strlen(base), base, fd);
		i = i + ft_putchangebase(nbr % ft_strlen(base), base, fd);
	}
	else
	{
		i = i + ft_putchar_fd(base[nbr], fd);
	}
	return (i);
}

int	ft_putpointer(unsigned long long nbr, int fd)
{
	char	*tab;
	int		i;

	tab = "0123456789abcdef";
	i = 0;
	if (nbr > 15)
	{
		i = ft_putpointer(nbr / 16, fd);
		i = i + ft_putpointer(nbr % 16, fd);
	}
	else
	{
		i = i + ft_putchar_fd(tab[nbr], fd);
	}
	return (i);
}
