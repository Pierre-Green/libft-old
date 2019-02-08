/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:23:12 by pierre            #+#    #+#             */
/*   Updated: 2019/02/08 15:20:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"
#include "ft_io.h"

static t_printf		*init(int fd, char *format, va_list params)
{
	t_printf		*state;

	if (!(state = ft_memalloc(sizeof(t_printf))))
		return (NULL);
	state->format = format;
	state->length = 0;
	state->fd = fd;
	va_copy(state->params, params);
	va_copy(state->it_params, params);
	return (state);
}

static t_part		init_part()
{
	t_part			part;

	part.nu = 0;
	part.flags = 0;
	part.width_p = false;
	part.width = 0;
	part.precision_p = false;
	part.precision = 0;
	part.length = 0;
	part.modifier = 0;
	part.value.i = 0;
	part.value.ptr = NULL;
	part.value.d = 0;
	return (part);
}

static int			cprintf(int fd, char *format, va_list params)
{
	t_printf		*state;

	if (!(state = init(fd, format, params)))
		return (INIT_ERROR);
	while (*state->format)
	{
		state->part = init_part();
		if (*state->format != FORMAT_BEGIN)
			ft_print_noph(state);
		if (*state->format == FORMAT_BEGIN)
			if(!ft_print_ph(state))
				return (PH_ERROR);
	}
	return (state->length);
}

int					ft_printf(const char *format, ...)
{
	va_list			values;
	int				result;

	va_start(values, format);
	result = cprintf(1, (char *)format, values);
	va_end(values);
	return (result);
}
