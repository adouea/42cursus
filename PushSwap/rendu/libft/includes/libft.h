/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:49:55 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:15:41 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>		// NULL, size_t type
# include <stdlib.h>    	// malloc(), free()
# include <unistd.h>    	// write(), read(), open(), close(), ...
# include <fcntl.h>			// macro to open files (O_CREAT, O_RDONLY ..)
# include <stdint.h>		// cross-compiler types
# include <limits.h>		// limits of types (INT_MAX, LONG_MAX, ...)
# include <stdarg.h>		// variable number of arguments
# include "get_next_line.h"
# include "ft_printf.h"

// implementation of a linked list
// @param content	--> void pointer to content of the node
// @param next	--> pointer to next element of linked list

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Chars

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_ishexadigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
void			ft_putchar_fd(char c, int fd);
int				ft_toupper(int c);
int				ft_tolower(int c);

//Checkers

int				ft_is_int(char *number);
int				ft_is_long(char *number);
int				ft_is_number(char *n);

//Lists

void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstm(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

//Memory

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_free_double(void ***to_free, int n_arr);
void			*ft_free_single(void **to_free);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_raise_error(char *text, int end);

//Numbers

double			ft_atod(char *s);
double			ft_atof(const char *nptr);
int				ft_atoi(const char *nptr);
int				ft_atoi_base(const char *str, int str_base);
long			ft_atol(const char *str);
char			ft_bin_to_char(int *bin_char);
void			ft_bitprint(unsigned char octet);
unsigned char	ft_bitrev(unsigned char octet);
unsigned char	ft_bitswap(unsigned char octet);
void			ft_char_to_bin(char c, int *bin_char);
float			ft_fmod(float number);
char			*ft_itoa(int n);
char			*ft_litoa(long n);
long			ft_mod(long number);
size_t			ft_nbrlen(size_t nbr, int base);
float			ft_part_dec(float number);
float			ft_part_int(float number);
float			ft_pow(int base, int exp);
void			ft_print_hex(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_round_to_int(double number);
float			ft_xatof(char *str_n);
int				ft_xatoi(char *str);
char			*ft_xitoa(int n, int capital);

//Strings

char			*ft_append_char(char to_add, char **str);
int				ft_count_occ(char *str, char to_find);
int				ft_find_index(char *str, char value);
size_t			ft_n_substr(char const *str, char char_split);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif
