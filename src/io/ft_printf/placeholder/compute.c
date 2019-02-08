/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 00:17:07 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 19:52:31 by pguthaus         ###   ########.fr       */
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
	if (state->part.modifier == CUMHX || state->part.modifier == CUHEX)
		ft_pfxX(state);
	if (state->part.modifier == CACHR || state->part.modifier == CAWCH)
		ft_pfc(state);
	if (state->part.modifier == CASTR)
		ft_pfs(state);
	if (state->part.modifier == CCURL)
		ft_pfn(state);
	if (state->part.modifier == CDMHX || state->part.modifier == CDHEX)
		ft_pfaA(state);
	if (state->part.modifier == CDMEX || state->part.modifier == CDEXP)
		ft_pfeE(state);
	if (state->part.modifier == CDDEC)
		ft_pffF(state);
	if (state->part.modifier == CDMGE || state->part.modifier == CDGEN)
		ft_pfgG(state);
}
