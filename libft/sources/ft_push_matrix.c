/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:55:05 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/10 14:52:04 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_matrix(char ***matrix, char *str)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	i = 0;
	tmp = *matrix;
	if (tmp == 0)
	{
		tmp2 = malloc(sizeof(char *) * 2);
		tmp2[0] = ft_strdup(str);
		tmp2[1] = 0;
	}
	else
	{
		tmp2 = malloc((sizeof(char *) * (ft_matrixlen(tmp) + 2)));
		tmp2[0] = str;
		while (tmp[i] != 0)
		{
			tmp2[i + 1] = tmp[i];
			i++;
		}
		tmp2[i + 1] = 0;
	}
	free(*matrix);
	*matrix = tmp2;
}
