/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:34 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/09 18:32:31 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delsig(void)
{
	if (g_error == INEXECVE)
		return ;
	rl_on_new_line();
	rl_redisplay();
	ft_printf("  \b\b\n");
}

void	get_signal(int sig)
{
	if (sig == SIGINT)
	{
		if (g_error == INHEREDOC_FORK)
			exit(1);
		else if (g_error != INEXECVE && g_error != INHEREDOC)
		{
			delsig();
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_error = SIGC;
		}
	}
	else if (sig == SIGQUIT)
	{
		if (g_error == INHEREDOC_FORK)
			exit(0);
		delsig();
	}
}
