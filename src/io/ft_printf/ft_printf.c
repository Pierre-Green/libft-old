/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:23:12 by pierre            #+#    #+#             */
/*   Updated: 2019/01/25 00:15:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"

static t_printf		*init(int fd, char *format, va_list params)
{
	t_printf		*state;

	if (!(state = ft_memalloc(sizeof(t_printf))))
		return (NULL);
	state->format = format;
	state->part.formatters = NULL;
	state->part.last_formatter = NULL;
	state->length = 0;
	state->fd = fd;
	state->part.nu = 0;
	va_copy(state->params, params);
	return (state);
}

static int			cprintf(int fd, char *format, va_list params)
{
	t_printf		*state;

	if (!(state = init(fd, format, params)))
		return (INIT_ERROR);
	while (*state->format)
	{
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
