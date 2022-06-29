/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_shell_parse2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:00:32 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/29 18:01:08 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_dollar_parse_i(char *change, char *start)
{	
	int	i;

	if (change != NULL)
	i = ft_strlen(start) + ft_strlen(change);
	else
		i = ft_strlen(start);
	return (i);
}
