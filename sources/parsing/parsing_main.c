/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:30:48 by guyar             #+#    #+#             */
/*   Updated: 2022/07/01 08:24:57 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parsing(t_minishell *main, char *line)
{
	int	c;

	c = ft_check_syntaxe(line);
	if (c == -1)
	{
		g_error = ERRO_SYNTAXE;
		ft_printf("error syntaxe\n");
		return (-1);
	}
	else if (c == -2)
		return (-2);
	main->nbcmd = ft_nbcmd(line);
	main->splitcmd = ft_split_cmd(line, main->nbcmd);
	ft_create_command(main);
	ft_free_matrix(main->splitcmd);
	free(main->splitcmd);
	return (0);
}

void static	init_var(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

char	**ft_split_cmd(char *str, int nb)
{
	int		i;
	int		q;
	int		q2;
	int		p;
	char	**ret;

	ret = malloc((sizeof(char *)) * (nb + 1));
	init_var(&nb, &q, &q2, &p);
	i = -1;
	while (str[++i])
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
	}
	ret[nb] = ft_substr(str, p, i - p);
	ret[nb + 1] = 0;
	return (ret);
}
