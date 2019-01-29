/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:30:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/29 15:09:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool					ft_is_flags(t_printf *state)
{
	char				*pos;

	pos = state->format;
	return (*pos == FLAGS_LEFT_JUSTIFY || *pos == FLAGS_FILL_WITH_0
		|| *pos == FLAGS_SIGN_OUTPUT || *pos == FLAGS_POSITIVE_BLANK
		|| *pos == FLAGS_ALTERNATE_PRINT);
}
