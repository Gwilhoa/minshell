/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:34 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/06 15:01:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delsig(void)
{
	rl_on_new_line();
	rl_redisplay();
	write(2, "  ", 2);
	write(2, "\b\b", 2);
}

void	get_signal(int sig)
{
	if (sig == SIGINT)
	{
		waitpid(0, NULL, 0);
		if (g_error != INEXECVE)
		{
			delsig();
			write(2, "\n", 1);
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_error = SIGC;
		}
		g_error = SIGC;
	}
	else if (sig == SIGQUIT)
		delsig();
	else if (sig == SIGKILL)
	{
		waitpid(0, NULL, 0);
		exit(0);
	}
}

void	useless_sig(int sig)
{
	ft_printf("\n");
	g_error = SIGC;
	(void) sig;
	return ;
}
