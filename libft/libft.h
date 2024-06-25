/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senayat <senayat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:52:10 by senayat           #+#    #+#             */
/*   Updated: 2024/06/24 23:45:11 by senayat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

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

// memory allocation and manipulation
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_free_tab(void **tab);

// char classification and conversion
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

// string manipulation
int				ft_atoi(const char *str);
int				ft_isinteger(const char *str, int *n);
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
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_elem);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

// array_list -> dynamic array
t_array_list	*array_list_create(size_t capacity);
void			array_list_clear(t_array_list *list);
void			array_list_destroy(t_array_list *list);
int				array_list_isempty(t_array_list *list);
int				array_list_set(t_array_list *list, size_t index, int new_item);
int				array_list_get(t_array_list *list, size_t index, int *item);
int				array_list_find(t_array_list *list, int item);
int				array_list_del(t_array_list *list, size_t index);
void			array_list_double_capacity(t_array_list *list);
void			array_list_add(t_array_list *list, int new_item);
void			array_list_insert(t_array_list *list,
					size_t index, int new_item);

// puts and printf
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
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
