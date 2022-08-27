/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:13:38 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/30 11:34:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **env)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		path = ft_getenv("PWD", env);
	ft_printf("%s\n", path);
	free(path);
	exit(0);
}
