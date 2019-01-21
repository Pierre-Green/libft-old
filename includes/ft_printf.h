/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:50:44 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/21 20:46:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

# define MALLOC_ERROR -42
# define FORMAT_BEGIN_ERROR -1

# define FORMAT_BEGIN '%'

typedef enum			e_types
{
	DEFAULT,
	INT
}						t_types;

typedef struct			s_formatter
{
	char				*(*f)(char *);
	struct s_formatter	*next;
}						t_formatter;

typedef struct			s_printf
{
	const char			*format;
	va_list				*values;
	char				*pos;
	t_formatter			*formatters;
	t_formatter			*last_formatter;
	t_types				type;
}						t_printf;

int						ft_printf(const char *format, ...);

t_formatter				*ft_init_formatters(t_printf *state);

int16_t					ft_configure_formatters(t_printf *state);

void					ft_add_formatter(char *(*f)(char *), t_printf *state);

#endif
