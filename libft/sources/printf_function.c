/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:17:56 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/12 13:55:56 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i = ft_putunsigned(nb / 10);
		i = i + ft_putunsigned(nb % 10);
	}
	else
	{
		i = i + ft_putchar_fd(nb + 48, 1);
	}
	return (i);
}

int	ft_puthexnbr(unsigned int nbr, const char *base)
{
	int	i;

	i = 0;
	if (nbr > 15)
	{
		i = ft_puthexnbr(nbr / 16, base);
		i = i + ft_puthexnbr(nbr % 16, base);
	}
	else
	{
		i = i + ft_putchar_fd(base[nbr], 1);
	}
	return (i);
}

int	ft_putpointer(unsigned long long nbr)
{
	char	*tab;
	int		i;

	tab = "0123456789abcdef";
	i = 0;
	if (nbr > 15)
	{
		i = ft_putpointer(nbr / 16);
		i = i + ft_putpointer(nbr % 16);
	}
	else
	{
		i = i + ft_putchar_fd(tab[nbr], 1);
	}
	return (i);
}
