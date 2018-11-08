/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:30:46 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/08 19:08:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

# define ISWHITESPACE(c) (c == ' ' ? 1 : (c == '\n' ? 1 : (c == '\t' ? 1 : 0)))
# define ABS(v) (v < 0 ? -v : v)

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

void	*ft_memset(void *s, int c, size_t n);

void 	ft_bzero(void *s, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memalloc(size_t size);

void	ft_memdel(void **ap);

char	*ft_strcat(char *dest, const char *src);

char	*ft_strncat(char *dest, const char *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strstr(const char *haystack, const char *needle);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dest, const char *src);

char	*ft_strncpy(char *dest, const char *src, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnew(size_t size);

void	ft_strdel(char **as);

void	ft_strclr(char	*s);

void	ft_striter(char *s, void (*f)(char *));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strmap(char const *s, char (*f)(char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strequ(char const *s1, char const *s2);

int		ft_strnequ(char const *s1, char const *s2, size_t n);

char	*ft_strsub(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

/*
 ** Return a copy of s without any whitespace (' ', '\n', '\t')
*/
char	*ft_strtrim(char const *s);

/*
 ** Split a string around c return an array of the splited parts
*/
char	**ft_strsplit(char const *s, char c);

/*
 ** Convert an int into a string
*/
char	*ft_itoa(int n);

/*
 ** Put a char in the stdout
*/
void	ft_putchar(char c);

/*
 ** Put a char in a specified file descriptor
*/
void	ft_putchar_fd(char c, int fd);

/*
 ** Put a string in the stdout
*/
void	ft_putstr(char const *s);

/*
 ** Put a string in a specified file descriptor
*/
void	ft_putstr_fd(char const *s, int fd);

/*
 ** Put a string with a \n at the end in the stdout
*/
void	ft_putendl(char const *s);

/*
 ** Put a string with a \n at the end in a specified file descriptor
*/
void	ft_putendl_fd(char const *s, int fd);

/*
 ** Put a number in the stdout
*/
void	ft_putnbr(int n);

/*
 ** Put a number in a specified file descriptor
*/
void	ft_putnbr_fd(int n, int fd);

#endif
