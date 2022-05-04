/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:13:38 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/03 15:54:03 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * @brief function bash pwd
 */
void	ft_pwd(char **env)
{
	ft_printf("%s\n", ft_getenv("PWD", env));
}
