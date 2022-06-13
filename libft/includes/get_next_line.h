/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:47:33 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/18 16:47:33 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFFER_SIZE 30

int		ft_search(char *str, int charset);
char	*get_next_line(int fd);
char	*ft_has_nl(char *ret, char *reste);
char	*ft_init(char *ret, char *str, int r);
int		reader(char **str, int fd);

#endif
