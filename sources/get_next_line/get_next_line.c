/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:25:15 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/18 16:25:15 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search(char *str, int charset)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == charset)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_has_nl(char *ret, char *rest)
{
	char	*temp;
	int		i;
	int		n;

	n = ft_search(ret, '\n');
	i = 0;
	temp = ft_strdup(ret + n + 1);
	while (temp[i] != 0)
	{
		rest[i] = temp[i];
		i++;
	}
	free(temp);
	rest[i] = 0;
	ret[n + 1] = 0;
	return (ret);
}

char	*ft_init(char *ret, char *str, int r)
{
	char	*temp;

	str[r] = '\0';
	if (!ret)
	{
		ret = malloc(1);
		ret[0] = 0;
	}
	temp = ft_strjoin(ret, str);
	if (!temp)
		return (0);
	free(ret);
	free(str);
	return (temp);
}

int	reader(char **str, int fd)
{
	char	*ret;
	int		r;

	ret = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, ret, BUFFER_SIZE);
	*str = ret;
	if (r <= 0)
		free(*str);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1];
	char		*str;
	char		*ret;
	int			r;

	ret = 0;
	if (fd >= 0 && *rest)
	{
		ret = ft_strdup(rest);
		*rest = 0;
	}
	r = 1;
	while (r > 0 || (ret && ft_search(ret, '\n') != -1))
	{
		if (!ret || ft_search(ret, '\n') == -1)
		{
			r = reader(&str, fd);
			if (r <= 0)
				return (ret);
			ret = ft_init(ret, str, r);
		}
		if (ret && ft_search(ret, '\n') != -1)
			return (ft_has_nl(ret, rest));
	}
	return (0);
}
