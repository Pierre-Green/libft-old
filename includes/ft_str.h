/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:03:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 18:24:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H
# include <stdlib.h>

char				*ft_strcat(char *dest, const char *src);

char				*ft_strncat(char *dest, const char *src, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strcpy(char *dest, const char *src);

char				*ft_strncpy(char *dest, const char *src, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char	*s);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

size_t				ft_strlen(const char *s);

size_t				ft_strflen(const char *str);

char				*ft_strdup(const char *s1);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

#endif
