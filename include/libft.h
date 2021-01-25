/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:12:07 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 16:41:49 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 20

int				get_next_line(const int fd, char **line);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}				t_gnl;

void			ft_bzero(void	*s, size_t	n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memcpy(void	*dst, const void	*src, size_t	n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memccpy(void	*dst, const void	*src, int c, size_t	n);
void			*ft_memmove(void	*dst, const	void	*src, size_t	len);
void			*ft_memchr(const	void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *stack, const char *needle, size_t len);
char			**ft_split_whitespaces(char *str);
char			*upper_case(char *str);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
int				ft_toupper(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isxdigit(int c);
int				ft_iscntrl(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isblank(int c);
void			ft_putnbr_base(int nb, char *base);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstsplit(char *s, char c);
size_t			ft_lstsize(t_list *lst);
char			*ft_strrev(char *str);
size_t			ft_sqrt(size_t nb);
size_t			ft_isprime(size_t nb);
size_t			ft_charinword(char *s, size_t i, char stop);
void			*ft_memcpynull(void *dst, const void *src, size_t len);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_list_size(t_list *lst);
int				ft_strncasecmp(char *str1, char *str2, int n);
int				ft_atoi_base(char *str, char *base);
int             ft_whitespace(char c);
#endif
