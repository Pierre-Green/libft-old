/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:22:53 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/21 21:00:23 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"
#include "ft_utils.h"

t_formatter		*ft_init_formatters(t_printf *state)
{
	if (!(state->formatters = ft_memalloc(sizeof(t_formatter))))
		return (NULL);
	state->formatters->f = NULL;
	state->formatters->next = NULL;
	state->last_formatter = state->formatters;
	return (state->formatters);
}

void			ft_add_formatter(char *(*f)(char *), t_printf *state)
{
	if (state->formatters->f == NULL) {
		state->formatters->f = f;
		return ;
	}
	if (!(state->last_formatter->next = ft_memalloc(sizeof(t_formatter))))
		return ;
	state->last_formatter = state->last_formatter->next;
	state->last_formatter->f = f;
	state->last_formatter->next = NULL;
}

static int16_t	(*ft_formatters_rooter())(t_printf *)
{
	
}

int16_t					ft_configure_formatters(t_printf *state)
{
	state->pos++;
	if (state->pos)
	return (0);
}
