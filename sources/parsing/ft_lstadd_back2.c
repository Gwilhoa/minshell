/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:06:40 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 17:11:25 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	addprocess(t_process **alst, t_process *new)
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
