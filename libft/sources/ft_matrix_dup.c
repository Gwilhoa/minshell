/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:53:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/10 08:55:56 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_dup(char **matrix)
{
	char	**new;
	int		i;

	new = malloc((ft_matrixlen(matrix) + 1) * sizeof(char *));
	i = 0;
	while (matrix[i] != 0)
	{
		new[i] = ft_strdup(matrix[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
