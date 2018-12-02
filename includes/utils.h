/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:52:45 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:49:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# define ABS(v) (v < 0 ? -v : v)
# define ISWHITESPACE(c) (c == ' ' ? 1 : (c == '\n' ? 1 : (c == '\t' ? 1 : 0)))

int					ft_atoi(const char *nptr);

char				*ft_itoa(int n);

void				ft_divmod(int *a, int *b);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

#endif