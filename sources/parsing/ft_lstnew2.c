/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:36:41 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 17:09:16 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	*ft_init_process(char *str)
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
	l->heredoc = NULL;
	return (l);
}
