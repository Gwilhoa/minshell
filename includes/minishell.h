/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:05:50 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/11 11:20:18 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <termios.h>
# include "color.h"
# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

int		ft_exit();
int		main(void);
int		loop(void);
int		getcmd(char **args);
int		ft_isredirecting(const STRING str);
int		cmd_bash();
char	*ft_echo(char **args);
char	*ft_pwd(void);
void	get_signal(int sig);

#endif
