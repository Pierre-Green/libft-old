/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:52:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 18:03:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>
# include <stdint.h>
# include "ft_bool.h"
# include <math.h>
# define ABS(v) (v < 0 ? -v : v)
# define ISWHITESPACE(c) (c == ' ' ? 1 : (c == '\n' ? 1 : (c == '\t' ? 1 : 0)))

int					ft_atoi(const char *nptr);

int					ft_atoi_consume(char **str);

size_t				ft_count_digits_int(intmax_t i);

size_t				ft_count_digits_uint(uintmax_t i);

char				*ft_int_to_hex(intmax_t i);

char				*ft_itoa(int n);

void				ft_divmod(int *a, int *b);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

int					ft_decimal2octal(int i);

double				ft_degrees_to_radian(double a);

#endif
