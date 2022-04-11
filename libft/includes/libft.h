/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:57:12 by gchatain          #+#    #+#             */
/*   Updated: 2022/03/01 11:44:11 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define STRING char *
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

/**
 * @brief 
 * recuperer la taille d'une variable en t_list
 * @param t_list 
 * @return int 
 */
int				ft_lstsize(t_list *lst);

/**
 * @brief transformer une chaine de charactere en integer
 * 
 * @param str 
 * @return int 
 */
int				ft_atoi(const char *str);

/**
 * @brief savoir si un nombre fais partie de l'alphabet 
 * ou un nombre dans la table ascii
 * 
 * @param c 
 * @return int 
 */
int				ft_isalnum(int c);

/**
 * @brief savoir si un nombre fais partie de l'alphabet dans la table ascii
 * 
 * @param c 
 * @return int 
 */
int				ft_isalpha(int c);

/**
 * @brief savoir la taille d'une chaine de charactere
 * 
 * @param str 
 * @return int 
 */
int				ft_strlen(char const *str);

/**
 * @brief savoir si un nombre fais partie de la table ascii
 * 
 * @param c 
 * @return int 
 */
int				ft_isascii(int c);

/**
 * @brief savoir si un nombre fais partie des chiffres dans la table ascii
 * 
 * @param c 
 * @return int 
 */
int				ft_isdigit(int c);

/**
 * @brief savoir si un nombre fais partie 
 * des charactere visible de la table ascii
 * 
 * @param c
 * @return int 
 */
int				ft_isprint(int c);

/**
 * @brief savoir si un nombre est une lettre 
 * minuscule d'apres la table ascii
 * 
 * @param c 
 * @return int 
 */
int				ft_tolower(int c);

/**
 * @brief savoir si un nombre est une lettre 
 * majuscule d'apres la table ascii
 * 
 * @param c 
 * @return int 
 */
int				ft_toupper(int c);

/**
 * @brief comparer 2 chaine de charactere
 * 
 * @param s1 chaine 1
 * @param s2 chaine 2
 * @param n la limite en taille a comparer
 * @return int 
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief comparer 2 pointeur quelque soit leur nature
 * 
 * @param str1 pointeur 1
 * @param str2 pointeur 2
 * @param n la limite a comparer
 * @return int 
 */
int				ft_memcmp(const void *str1, const void *str2, size_t n);

/**
 * @brief mais des 0 jusqu'a n sur un pointeur
 * 
 * @param s pointeur
 * @param n limiteur
 * @return void* 
 */
void			*ft_bzero(void *s, size_t n);

/**
 * @brief alloue de la memoire remplie directement par des 0
 * 
 * @param count taille
 * @param size sizeof(type)
 * @return void* 
 */
void			*ft_calloc(size_t count, size_t size);

/**
 * @brief renvoie un pointeur du dernier char c dans
 *  le pointeur s a la limite de n
 * 
 * @param s pointeur 
 * @param c char
 * @param n limiteur
 * @return void* 
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief copie les n premier octets de src dans dest
 * 
 * @param dest destination
 * @param src source
 * @param n limiteur
 * @return void* pointeur de dest
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief copie les n premier char elles peuvent se chevaucher
 * 
 * @param dest destination
 * @param src source
 * @param n limiteur
 * @return void* 
 */
void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief met des c dans le pointeur s jusqu'a n
 * 
 * @param s pointeur
 * @param c octet
 * @param n limiteur
 * @return void* 
 */
void			*ft_memset(void *s, int c, size_t n);

/**
 * @brief effectue une fonction avant de supprimer l'element d'un t_list
 * 
 * @param lst liste
 * @param del fonction
 */
void			ft_lstdelone(t_list *lst, void (*del)(int));

/**
 * @brief ecrit dans un file descriptor le charactere c 
 * (1 pour le terminal)
 * 
 * @param c char
 * @param fd file descriptor
 * @return renvoie 1
 */
int				ft_putchar_fd(char c, int fd);

/**
 * @brief ecrit dans un file descriptor la chaine de char str
 * (1 pour le terminal)
 * 
 * @param str chaine de char
 * @param fd file descriptor
 * @return renvoie taille de la chaine de char 
 */
int				ft_putstr_fd(const char *str, int fd);

/**
 * @brief ecrite dans un file descriptor un nombre
 * (1 pour le terminal)
 * 
 * @param nb nombre
 * @param fd file descriptor
 * @return taille du nombre (unite dizaine centaine etc..)
 */
int				ft_putnbr_fd(int nb, int fd);

/**
 * @brief effectue la fonction f sur tous les characteres de s
 * 
 * @param s 
 * @param f 
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief renvoie une chaine e char suivit d'un retour a la ligne 
 * 
 * @param str 
 * @param fd 
 */
void			ft_putendl_fd(char *str, int fd);

/**
 * @brief ajoute une liste chainee devant une liste chainee
 * ce qui a pour but d'en faire qu'une seule au pointeur alst
 * 
 * @param alst liste mis en arriere
 * @param n 
 */
void			ft_lstadd_front(t_list **alst, t_list *n);

/**
 * @brief ajoute une liste chainee derriere une liste chainee
 * ce qui a pour but d'en faire une seule au pointeur alst
 * 
 * @param alst 
 * @param n 
 */
void			ft_lstadd_back(t_list **alst, t_list *n);

/**
 * @brief effectue une fonction et supprime sur chaque element de la liste
 * 
 * @param lst t_list
 * @param del fonction
 */
void			ft_lstclear(t_list **lst);

/**
 * @brief effectue une fonction sur chaque element de la liste
 * 
 * @param lst t_list
 * @param f  fonction
 */
void			ft_lstiter(t_list *lst, void (*f)(int));

/**
 * @brief coupe un pointeur en plusieurs pointeur selon charset
 * 
 * @param str 
 * @param charset 
 * @return char** 
 */
char			**ft_split(const char *str, char charset);

/**
 * @brief renvoie un pointeur sur le premier c trouvé
 * 
 * @param s chaine char
 * @param c char
 * @return char* 
 */
char			*ft_strchr(const char *s, int c);

/**
 * @brief renvoie un pointeur alloue avec le meme contenu que le parametre donne
 * 
 * @param src 
 * @return char* 
 */
char			*ft_strdup(char const *src);

/**
 * @brief renvoie un pointeur alloue avec une unique chaine de char
 * 
 * @param dest 
 * @param src 
 * @return char* 
 */
char			*ft_strjoin(char const *dest, char const *src);

/**
 * @brief transformer un nombre en chaine de char
 * 
 * @param n 
 * @return char* 
 */
char			*ft_itoa(int n);

/**
 * @brief renvoie un pointeur ou il trouve little dans big
 * 
 * @param big 
 * @param little 
 * @param len 
 * @return char* 
 */
char			*ft_strnstr(const char	*big, const char *little, size_t len);

/**
 * @brief renvoie le reste apres le char c
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @brief permet de trimmer selon plusieurs char
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char			*ft_strtrim(char const *s1, char const *set);

/**
 * @brief 
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief permet de faire une chaine de char avec 
 * le retour d'une fonction avec toutes la chaine en paramettre
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief permet de mettre a dest le contenu de src en plus
 * 
 * @param dest 
 * @param src 
 * @param size 
 * @return renvoie la taille de dest
 */
size_t			ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief copie size charactere de source dans dest et renvoie la taille
 * 
 * @param dest 
 * @param src 
 * @param size 
 * @return size_t 
 */
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief permet de creer une nouvelle liste chainee typee t_list
 * 
 * @param content 
 * @return t_list* 
 */
t_list			*ft_lstnew(int content);

/**
 * @brief renvoie le dernier maillon d'une liste chainee
 * 
 * @param lst 
 * @return t_list* 
 */
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(int));
int				putnbr(int nb);
int				ft_putunsigned(unsigned int nb, int fd);
int				ft_putchangebase(unsigned int nbr, const char *base, int fd);
int				ft_putpointer(unsigned long long nbr, int fd);
int				function_parser(va_list args, int c);
/**
 * @brief permet d'afficher des données
 * 
 * @param str 
 * @param ... 
 * @return int 
 */
int				ft_printf(const char *str, ...);
#endif
