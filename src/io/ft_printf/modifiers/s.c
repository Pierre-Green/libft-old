/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:04:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 14:03:04 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Flags: 0/-
** Width
** Precision
** Length: wchar
*/
void		ft_pfs(t_printf *state)
{
	size_t	length;
	ft_next_param(state);
	ft_putstr(state->part.value.str);
}
