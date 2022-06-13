/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:24:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/12 14:07:32 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	other(int neg)
{
	if (neg > 0)
		return (-1);
	return (0);
}

int	ft_atoi(char const *str)
{
	int			i;
	long int	ret_int;
	int			neg;

	ret_int = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		||str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i += 1;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if (ret_int * neg > 2147483647 || ret_int * neg < -2147483648)
			return (other(neg));
		ret_int = ret_int * 10 + (str[i] - 48);
		i++;
	}
	return (ret_int * neg);
}
