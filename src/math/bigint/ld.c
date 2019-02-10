/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:17:12 by pierre            #+#    #+#             */
/*   Updated: 2019/02/10 22:50:43 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/bigint.h"

t_bigint				*ft_bint_ldinit(long double ld)
{
	t_bigint 			*bigint;
	unsigned char		buff[BUFF_MAX];
	size_t				len;

	bigint = ft_bint_init();
	len = 0;
	while (ld >= 1)
	{
		buff[BUFF_MAX - 1 - len] = ld % 10;
		ld /= 10;
		len++;
	}
	return (bigint);
}
