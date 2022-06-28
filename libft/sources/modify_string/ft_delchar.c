/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:38 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/28 15:55:54 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delchar(char **str, int index)
{
	char	*start;
	char	*end;

	start = ft_substr(*str, 0, index);
	end = ft_substr(*str, index + 1, ft_strlen(*str));
	free(*str);
	*str = ft_strjoin_free(start, end);
}
