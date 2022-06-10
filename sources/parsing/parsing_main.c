/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/06/10 19:12:07 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsing(t_minishell *main)
{
	if (ft_check_syntaxe(main->str) == -1)
	{
		g_error = ERRO_SYNTAXE;
		return (-1);
	}
	main->nbcmd = ft_nbcmd(main->str);
	main->splitcmd = ft_split_cmd(main->str, main->nbcmd);
	ft_creat_command(main);
	return (0);
}

char	**ft_split_cmd(char *str, int nb)
{
	int		i;
	int		q;
	int		q2;
	int		p;
	char	**ret;

	q = 0;
	q2 = 0;
	i = 0;
	p = 0;
	ret = malloc((sizeof(char *)) * (nb + 1));
	nb = 0;
	while (str[i])
	{
		if (str[i] == '"' && q != 1)
			q2 = -q2 + 1;
		else if (str[i] == '\'' && q2 != 1)
			q = -q + 1;
		if (str[i] == '|' && q == 0 && q2 == 0)
		{
			ret[nb] = ft_substr(str, p, i - p);
			nb++;
			p = i + 1;
		}
		i++;
	}
	ret[nb] = ft_substr(str, p, i - p);
	ret[nb + 1] = 0;
	return (ret);
}
