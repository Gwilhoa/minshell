/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:48:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/12 13:56:24 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	function_parser(va_list args, int c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		size = ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
		size = ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'x')
		size = ft_puthexnbr(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (c == 'X')
		size = ft_puthexnbr(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (c == 'p')
	{
		size = ft_putstr_fd("0x", 1);
		size = size + ft_putpointer(va_arg(args, unsigned long long));
	}
	else if (c == '%')
		size = ft_putchar_fd('%', 1);
	else if (c == 'u')
		size = ft_putunsigned(va_arg(args, unsigned int));
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			size = size + function_parser(args, str[i]);
		}
		else
			size = size + ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (size);
}
