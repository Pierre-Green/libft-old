/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:24:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:24:53 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/bigint.h"

void				ft_bint_init(t_bigint *des)
{
	size_t			current;

	current = 0;
	while (current < BIGINT_LEN)
	{
		des->ints[current] = 0;
		current++;
	}
}
