/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:39:50 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/05 12:53:58 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

# define BUFFER_SIZE 1
# define SETS "cspdiuxX%ngfe"
# define HEX "0123456789abcdef"

typedef __UINTPTR_TYPE__	t_uintptr;

typedef long long int		t_intmax;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct		s_printf
{
	int		minus;
	int		zero;
	int		space;
	int		plus;
	int		hash;
	int		width;
	int		precision;
	char	mask;
	char	conversion;
	va_list	argv;
	int		size;
	char	*format;
	char	*summary;
}					t_printf;

int					ft_printf(const char *format, ...);
void				processline(t_printf **bag);
t_printf			*initilialize(const char *format);
void				reinitialize(t_printf **bag);
int					destructor(char *format, t_printf **bag);
char				*ft_strldup(char *format);
void				check_flags(t_printf **bag);
void				check_precision(t_printf **bag);
void				check_width(t_printf **bag);
void				check_conversion(t_printf **bag);
void				executer(t_printf **bag);
void				putspaces(int nspaces);
void				putstr_printf(t_printf **bag);
int					ft_putnstr(t_printf **bag, char *str);
void				putchar_printf(t_printf **bag);
void				putpercent_printf(t_printf **bag);
void				putnbr_printf(t_printf **bag);
size_t				ft_nbrlen(t_intmax num);
void				putzeros(int nzeros);
size_t				ft_nbrlenprec(t_intmax num);
void				ft_putnbrprintfprec(t_intmax nb, t_printf **bag);
void				ft_putnbrprintf(t_intmax nb, t_printf **bag);
void				putnbr_print_0(t_printf **bag);
t_intmax			putnbr_check_zero(t_printf **bag);
void				putnbr_width_prec(t_printf **bag, int len, int neg);
void				putnbr_prec_len(t_printf **bag, int len);
void				putnbr_width_zeros(t_printf **bag, int len,
					int neg, t_intmax number);
void				putunsigned_printf(t_printf **bag);
size_t				ft_nbrulen(t_intmax num);
t_intmax			putunsigned_check_zero(t_printf **bag);
void				ft_putnbru(unsigned int nb, t_printf **bag);
void				puthex_printf(t_printf **bag);
size_t				ft_nbrhexlen(t_intmax num);
void				printf_hex(t_intmax number, t_printf **bag);
void				ft_putnbr_base(t_intmax nb, char *str, t_printf **bag);
void				putmemory_printf(t_printf **bag);
size_t				ft_nbrmemlen(t_uintptr num);
void				ft_putnbr_base_mem(t_uintptr nb, char *str, t_printf **bag);
void				printf_mem(t_uintptr number, t_printf **bag);
void				printf_0x(t_printf **bag);
int					puthex_hash(t_printf **bag);
void				putmemory_nill(t_printf **bag);
int					putnbr_plus_space_bonus(t_intmax number, t_printf **bag);
int					putnbr_plus_space2_bonus(t_intmax number, t_printf **bag);
void				putnbr_print_plus_space(int symbol,
					t_intmax number, t_printf **bag);
int					putnbr_plus_space3_bonus(t_intmax number, t_printf **bag);
void				putnbr_print_plus_space2(int symbol,
					t_intmax number, t_printf **bag);
void				putintpointer_printf(t_printf **bag);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nb);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *str);
char				**ft_split(char const *s, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_swap(int *a, int *b);
int					ft_tolower(int ch);
int					ft_toupper(int ch);

#endif
