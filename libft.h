/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:30:46 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/07 18:41:18 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

# define IsWhiteSpace(c) (c == ' ' ? 1 : (c == '\n' ? 1 : (c == '\t' ? 1 : 0)))

void	*ft_memalloc(size_t size);

void	ft_memdel(void **ap);

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

char	*ft_strtrim(char const *s);

char	**ft_strsplit(char const *s, char c);

char	*ft_itoa(int n);

void	ft_putchar(char c);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr(char const *s);

void	ft_putstr_fd(char const *s, int fd);

void	ft_putendl(char const *s);

void	ft_putendl_fd(char const *s, int fd);

void	ft_putnbr(int n);

void	ft_putnbr_fd(int n, int fd);

#endif