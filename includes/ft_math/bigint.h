/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:11:40 by pierre            #+#    #+#             */
/*   Updated: 2019/02/10 22:32:27 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_BIGINT_H
# define FT_MATH_BIGINT_H
# include <stdlib.h>
# include "ft_bool.h"
# define BUFF_MAX 5000

typedef struct		s_bigint
{
	unsigned char	*digits;
	size_t			digits_count;
	size_t			digits_allocated;
	t_bool			is_negative;
}					t_bigint;

t_bigint			*ft_bint_init();

t_bigint			*ft_bint_iinit(int i);

t_bigint			*ft_bint_ldinit(long double ld);

#endif
