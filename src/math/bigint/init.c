/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:24:34 by pierre            #+#    #+#             */
/*   Updated: 2019/02/10 22:26:19 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/bigint.h"

t_bigint			*ft_bint_init()
{
	t_bigint		*bigint;

	if (!(bigint = malloc(sizeof(t_bigint))))
		return (NULL);
	bigint->digits = NULL;
	bigint->digits_count = 0;
	bigint->digits_allocated = 0;
	bigint->is_negative = false;
	return (bigint);
}
