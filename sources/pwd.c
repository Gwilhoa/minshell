/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:13:38 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/06 14:54:40 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * @brief function bash pwd
 * 
 * @return int (1 if success)
 */
char	*ft_pwd(void)
{
	char	dir[256];

	getcwd(dir, sizeof(dir));
	return (ft_strdup(dir));
}
