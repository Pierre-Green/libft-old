/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:01:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:01:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_BIGINT_H
# define FT_MATH_BIGINT_H
# include <stdlib.h>
# include <stdint.h>
# include "ft_bool.h"
# define BIGINT_LEN (128 / 4)
# define WORD_MAX ((uint64_t)0xFFFFFFFF)

typedef struct		s_bigint
{
	uint32_t		ints[BIGINT_LEN];
}					t_bigint;

void				ft_bigint_init(t_bigint *des);

/*
** Arithmetics operation
*/
void				ft_bigint_add(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_sub(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_mul(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_div(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_mod(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_divmod(t_bigint *a, t_bigint *b, t_bigint *div,
		t_bigint *mod);

void				ft_bigint_pow(t_bigint *a, t_bigint *pow, t_bigint *res);

/*
** Bitwise operation
*/

void				ft_bigint_bwa(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_bwo(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_bwx(t_bigint *a, t_bigint *b, t_bigint *des);

void				ft_bigint_bsl(t_bigint *a, t_bigint *des, int n);

void				ft_bigint_bsr(t_bigint *a, t_bigint *des, int n);

/*
** Others
*/
void				ft_bigint_tostring(t_bigint *a, char *des, int max);

#endif
