/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:57:17 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/19 20:23:07 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// buffer for get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define S_QUOTE '\''
# define D_QUOTE '\"'

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// Linked list structure
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Mandatory libft functions
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *ptr, int c, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *str_lg, const char *str_sm, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

// Bonus libft functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Other libft functions
int		ft_arrlen(char **arr);
void	ft_free_str_arr_2d(char ***arr);
void	ft_free_str_arr(char **arr);
char	***ft_split_quotes_2d(char **arr, char c);
char	**ft_split_quotes(char *str, char c);
int		ft_strcmp(char *s1, char *s2);
char	**ft_strdup_arr(char *arr[]);
char	*ft_strreplace(char *str, char *old_s, char *new_s, int start_i);
double	ft_atof(char *str);

// get_next_line functions
// File: get_next_line.c
char	*get_next_line(int fd);

// ft_printf functions
// File: ft_printf_utils.c
int		print_char(int c);
int		print_str(char *str);
int		print_int(int n);
int		print_uint(unsigned int n);
// File: ft_printf_utils2.c
int		print_hex(unsigned long long n, char c);
int		print_ptr(void *ptr);
// File: ft_printf.c
int		ft_printf(const char *str, ...);

// ft_printf_fd functions
// File: ft_printf_fd_utils.c
int		print_char_fd(int c, int fd);
int		print_str_fd(char *str, int fd);
int		print_int_fd(int n, int fd);
int		print_uint_fd(unsigned int n, int fd);
// File: ft_printf_fd_utils2.c
int		print_hex_fd(unsigned long long n, char c, int fd);
int		print_ptr_fd(void *ptr, int fd);
// File: ft_printf_fd.c
int		ft_printf_fd(int fd, const char *str, ...);

#endif
