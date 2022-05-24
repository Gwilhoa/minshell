/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:36:41 by guyar             #+#    #+#             */
/*   Updated: 2022/05/24 16:30:01 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	*ft_lstnew2(char *str)
{
	t_process	*l;

	l = malloc(sizeof(t_process));
	if (!l)
		return (0);
	l->cmd = str;
	l->outfd = 0;
	l->infd = 0;
	l->outfile = NULL;
	l->infile = NULL;
	l->next = NULL;
	return (l);
}
