/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:50:44 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/25 00:19:04 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_bool.h"

# define INIT_ERROR -1
# define PH_ERROR -2

# define FORMAT_BEGIN '%'

typedef struct			s_formatter
{
	char				*(*f)(char *, void *);
	struct s_formatter	*next;
}						t_formatter;

typedef struct			s_part
{
	uint16_t			nu;
	t_formatter			*formatters;
	t_formatter			*last_formatter;
}						t_part;

typedef struct			s_printf
{
	int					fd;
	char				*format;
	va_list				params;
	uint32_t			length;
	t_part				part;

}						t_printf;

int						ft_printf(const char *format, ...);

/*
** Placeholder functions
*/
t_bool					ft_is_parameter(t_printf *state);

void					ft_apply_parameter(t_printf *state);

t_bool					ft_is_flags(t_printf *state);

void					ft_apply_flags(t_printf *state);

t_bool					ft_is_width(t_printf *state);

void					ft_apply_width(t_printf *state);

t_bool					ft_is_precision(t_printf *state);

void					ft_apply_precision(t_printf *state);

t_bool					ft_is_length(t_printf *state);

void					ft_apply_length(t_printf *state);

t_bool					ft_is_type(t_printf *state);

void					ft_apply_type(t_printf *state);

/*
** Utils
*/
void					ft_print_noph(t_printf *state);

t_bool					ft_print_ph(t_printf *state);

t_bool					ft_validate_ph(t_printf *state);

t_bool					ft_compute_and_print_ph(t_printf *state);

#endif
