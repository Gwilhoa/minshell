/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:38 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/13 10:49:46 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delchar(char **str, int index)
{
	char	*start;
	char	*end;

	start = ft_substr(*str, 0, index);
	end = ft_substr(*str, index + 1, ft_strlen(*str));
	*str = ft_strjoin(start, end);
	free(start);
	free(end);
}
