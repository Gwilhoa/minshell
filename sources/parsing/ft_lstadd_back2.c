/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:06:40 by guyar             #+#    #+#             */
/*   Updated: 2022/05/23 17:31:42 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back2(t_process **alst, t_process *new)
{
	t_process	*t;
	int			i;

	i = 0;
	if (alst && *alst)
	{
		t = *alst;
		while (t->next)
		{
			t = t->next;
			i++;
		}
		t->next = new;
	}
	else if (alst)
		*alst = new;
	new->process_nb = i;
}
