/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:11:34 by gchatain          #+#    #+#             */
/*   Updated: 2022/05/31 15:17:28 by gchatain         ###   ########lyon.fr   */
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
		if (g_error != INEXECVE)
		{
			delsig();
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_error = SIGC;
		}
	}
	else if (sig == SIGQUIT)
		delsig();
	else if (sig == SIGKILL)
	{
		waitpid(0, NULL, 0);
		exit(0);
	}
}
