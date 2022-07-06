/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:34 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/06 10:10:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delsig(void)
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", 2);
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
			ft_putchar_fd('\n', 2);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
		}
		g_error = SIGC;
	}
	else if (sig == SIGQUIT)
	{
		if (g_error == INHEREDOC)
			return ;
		else if (g_error == INEXECVE)
			g_error = 131;
		else
			delsig();
	}
}

void	sigfork(int sig)
{
	if (SIGINT == sig)
		g_error = SIGC;
}
