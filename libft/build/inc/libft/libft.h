/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:05:46 by fcorri            #+#    #+#             */
/*   Updated: 2024/01/23 15:59:54 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// INCLUDES

# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

// DEFINES

# define SIZE 8

// MANDATORY

int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlen(const char *s);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcpy_new(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
int						ft_atoi(const char *nptr);
long					ft_atol(const char *nptr);
void					*ft_calloc(size_t nmemb, size_t size);
char					*ft_strdup(const char *s);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);

// NON MANDATORY

char					*ft_strndup(const char *s, size_t n);
void					ft_error(char *caller, char *message);
int						ft_abs(int nbr);

// MEMORY UTILS

int						ft_cmp_bytes(uintptr_t *p_p1, uintptr_t *p_p2,
							size_t *p_n);
int						ft_cmp_words(uintptr_t *p_p1, uintptr_t *p_p2,
							size_t *p_n);
size_t					ft_chr_words(uintptr_t *p_dest, unsigned long input,
							size_t n);
size_t					ft_cpy_words(uintptr_t *p_dest, uintptr_t *p_src,
							size_t n);
void					ft_move_word(uintptr_t dest, uintptr_t src);
size_t					ft_move_words(uintptr_t *p_dest, uintptr_t *p_src,
							size_t n);
size_t					ft_set_words(uintptr_t *p_dest, unsigned long word,
							size_t n);
unsigned long			ft_init_word(unsigned char c);
unsigned long			ft_init_one(void);
unsigned long			ft_read_word(uintptr_t src);

// DECORATORS

void					*ft_malloc_soul(size_t size);

// DATA STRUCTURES

// LIST

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
size_t					ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list **lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

// DOUBLE CONNECTED LIST

typedef struct s_int_dlist
{
	int					content;
	struct s_int_dlist	*next;
	struct s_int_dlist	*prev;
}						t_int_dlist;

t_int_dlist				*ft_int_dlst_new(int content);
void					ft_int_dlst_add_front(t_int_dlist **lst,
							t_int_dlist *new);
size_t					ft_int_dlst_size(t_int_dlist *lst);
t_int_dlist				*ft_int_dlst_last(t_int_dlist *lst);
void					ft_int_dlst_add_back(t_int_dlist **lst,
							t_int_dlist *new);
void					ft_int_dlst_del_one(t_int_dlist **lst);
void					ft_int_dlst_clear(t_int_dlist **lst);
void					ft_int_dlst_iter(t_int_dlist *lst, void (*f)(int *));
t_int_dlist				*ft_int_dlst_map(t_int_dlist *lst, int (*f)(int));

#endif
