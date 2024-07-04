/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:52:10 by senayat           #+#    #+#             */
/*   Updated: 2024/07/04 22:13:56 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef int	t_bool;
# define TRUE	1
# define FALSE	0

typedef int	t_error;
# define NO_ERR			0
# define SOME_ERR		1
# define EMPTY_PTR_ERR	2
# define MALLOC_ERR		3

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct t_array_list
{
	size_t	size;
	size_t	capacity;
	int		*items;
}	t_array_list;

// error management
t_bool			ft_set_err(int *error, t_error val);

// memory allocation and manipulation
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
t_bool			ft_set_free(void **ptr);
t_bool			ft_free_tab(void **tab);

// char classification and conversion
t_bool			ft_isalnum(int c);
t_bool			ft_isalpha(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isprint(int c);
t_bool			ft_isspace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

// string manipulation
int				ft_atoi(const char *str);
t_bool			ft_isinteger(const char *str, int *n);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// list -> linked list
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_elem);
size_t			ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_elem);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// array_list -> dynamic array
t_array_list	*array_list_create(size_t capacity);
t_bool			array_list_clear(t_array_list *list);
t_bool			array_list_destroy(t_array_list *list);
t_bool			array_list_isempty(t_array_list *list);
t_bool			array_list_set(t_array_list *list, size_t index, int new_item);
t_bool			array_list_get(t_array_list *list, size_t index, int *item);
t_bool			array_list_find(t_array_list *list, int item, size_t *index);
t_bool			array_list_del(t_array_list *list, size_t index);
t_bool			array_list_double_capacity(t_array_list *list);
t_bool			array_list_add(t_array_list *list, int new_item);
t_bool			array_list_insert(t_array_list *list,
					size_t index, int new_item);
t_bool			array_list_find_smallest(t_array_list *list, size_t *index);
t_bool			array_list_mean(t_array_list *list, long *mean);
int				array_list_cost_move_to_top(size_t size, size_t index);

// puts and printf
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl(char *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_printf(const char *s, ...);
size_t			ft_puts(const char *s);
size_t			ft_putc(int c);
size_t			ft_putd(int d);
size_t			ft_putp(void *addr);
size_t			ft_putu(unsigned int n);
size_t			ft_putx(unsigned int n, const char f);

#endif // LIBFT_H
