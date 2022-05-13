/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:36:41 by guyar             #+#    #+#             */
/*   Updated: 2022/05/13 14:40:28 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	*ft_lstnew2(char **splitcmdi)
{
	t_process	*l;

	l = malloc(sizeof(t_process));
	if (!l)
		return (0);
	l->fullcmd = splitcmdi;
	l->outfd = 0;
	l->infd = 0;
	l->outfile = NULL;
	l->next = NULL;
	return (l);
}
