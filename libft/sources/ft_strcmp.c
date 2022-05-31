/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:25:49 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/31 18:35:56 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *str, char *str2)
{
	int	size;
	
	if (ft_strlen(str) > ft_strlen(str2))
		size = ft_strlen(str);
	else
		size = ft_strlen(str2);
	return (ft_strncmp(str, str2, size));
}
