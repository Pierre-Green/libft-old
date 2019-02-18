/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:32:03 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/18 16:35:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/bigint.h"

void				ft_bigint_add(t_bigint *a, t_bigint *b, t_bigint *des)
{
	uint64_t		tmp;
	size_t			curr;
	size_t			carry;

	curr = 0;
	carry = 0;
	while (curr < BIGINT_LEN)
	{
		tmp = (uint64_t)a->ints[curr] + b->ints[curr] + carry;
		carry = (tmp > WORD_MAX);
		des->ints[curr] = (tmp & WORD_MAX);
	}
}
