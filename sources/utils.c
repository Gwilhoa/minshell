/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:23:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/14 11:24:08 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * @brief function to know if the string is a redirecting bash
 * 
 * @param str (at comparate)
 * @return int (1 is redirecting)
 */
int	ft_isredirecting(const STRING str)
{
	if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "<<", ft_strlen(str)) == 0)
		return (1);
	return (0);
}
