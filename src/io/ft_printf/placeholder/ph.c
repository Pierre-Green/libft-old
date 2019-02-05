/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:06:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 13:21:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool			ft_print_ph(t_printf *state)
{
	state->format++;
	if (ft_is_parameter(state))
		ft_apply_parameter(state);
	if (ft_is_flags(state))
		ft_apply_flags(state);
	if (ft_is_width(state))
		ft_apply_width(state);
	if (ft_is_precision(state))
		ft_apply_precision(state);
	if (ft_is_length(state))
		ft_apply_length(state);
	if (!ft_is_type(state))
		return (false);
	ft_apply_type(state);
	ft_root_ph(state);
	return (true);
}
