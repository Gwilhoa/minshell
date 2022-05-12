/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:36:41 by guyar             #+#    #+#             */
/*   Updated: 2022/05/12 18:11:24 by guyar            ###   ########.fr       */
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
	l->next = NULL;
	return (l);
}