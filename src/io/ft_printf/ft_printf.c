/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:23:12 by pierre            #+#    #+#             */
/*   Updated: 2019/01/21 20:46:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"

static t_printf		*get_state(const char *format, va_list *values)
{
	t_printf		*state;

	if (!(state = ft_memalloc(sizeof(t_printf))))
		return (NULL);
	state->format = format;
	state->values = values;
	state->pos = (char *)format;
	state->formatters = NULL;
	state->last_formatter = NULL;
	state->type = DEFAULT;
	return (state);
}


static int16_t		ft_next_part(t_printf *state)
{
	uint8_t			formatters_count;

	if (*state->pos != FORMAT_BEGIN)
		return (*state->pos == '\0' ? 0 : FORMAT_BEGIN_ERROR);
	ft_init_formatters(state);
	if ((formatters_count = ft_configure_formatters(state)) <= 0)
		return (formatters_count);
	return (0);
}

int					ft_printf(const char *format, ...)
{
    t_printf		*state;
	va_list			values;
	int16_t			curr_res;

	va_start(values, format);
	if (!(state = get_state(format, &values)))
		return (MALLOC_ERROR);
	while ((curr_res = ft_next_part(state)) > 0)
	{
		while (*state->pos != '\0' || *state->pos != FORMAT_BEGIN)
		{
			write(1, state->pos, 1);
			state->pos++;
		}
	}
	return (curr_res);
}
