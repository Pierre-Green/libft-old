/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:24:34 by pierre            #+#    #+#             */
/*   Updated: 2019/02/18 16:18:53 by pguthaus         ###   ########.fr       */
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
