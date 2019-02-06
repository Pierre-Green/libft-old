/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 00:17:07 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/06 22:45:33 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_root_ph(t_printf *state)
{
	if (state->part.nu == 0)
		ft_next_param(state);
	else
		ft_iparam(state);
	if (state->part.modifier == CSINT)
		ft_pfdi(state);
	if (state->part.modifier == CUOCT)
		ft_pfo(state);
	if (state->part.modifier == CUINT)
		ft_pfu(state);
	if (state->part.modifier == CACHR || state->part.modifier == CAWCH)
		ft_pfc(state);
	if (state->part.modifier == CASTR)
		ft_pfs(state);
}
