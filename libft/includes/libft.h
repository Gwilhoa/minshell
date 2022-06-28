/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:01:49 by gchatain          #+#    #+#             */
/*   Updated: 2022/06/28 12:31:57 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
# define STRING char *

void	ft_delchar(char **str, int index);
int		ft_atoi(char const *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		sizeint(long int n);
int		ft_lstsize(t_list *lst);
int		ft_matrix_size(const char **matrix);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		function_parser(va_list args, int c);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		print_nb(int nb, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_strlen(char const *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putunsigned(unsigned int nb);
int		ft_puthexnbr(unsigned int nbr, const char *base);
int		ft_putpointer(unsigned long long nbr);
int		ft_strcmp(char *str, char *str2);
int		ft_isspace(unsigned char c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_free_first(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char const *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_space(char *s1, char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**ft_matrix_dup(char **matrix);
void	ft_free_matrix(char **matrix);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_putendl_fd(char *str, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_disp_matrix(char **matrix);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_push_matrix(char ***matrix, char *str);
void	ft_push_back_matrix(char ***matrix, char *str);
void	ft_strreplace(char **str, char *rep);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(int));
t_list	*ft_lstnew(int content);
char	*ft_strtrim2(char *s1, char const *set);
char	*ft_malloc_strtrim(char *ret_str, int end, int start);
#endif
