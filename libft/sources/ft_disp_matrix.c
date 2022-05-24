/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:08:23 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/24 09:57:34 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_disp_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == 0)
		ft_printf("(null)");
	while (matrix[i] != 0)
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
}
