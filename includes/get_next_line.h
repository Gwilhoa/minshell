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

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFFER_SIZE 42

int		ft_search(char *str, int charset);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
char	*ft_strdup(char const *src);
char	*get_next_line(int fd);
char	*ft_has_nl(char *ret, char *reste);
char	*ft_init(char *ret, char *str, int r);
void	ft_cleaner(char *reste);
int		reader(char **str, int fd);
char	*ft_getallfile(int fd);

#endif
