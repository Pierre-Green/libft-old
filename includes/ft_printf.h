/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:50:44 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 18:16:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_bool.h"
# include "ft_io.h"
# include <stdio.h>

# define INIT_ERROR -1
# define PH_ERROR -2

# define FORMAT_BEGIN '%'

# define PARAMETER_END '$'

# define FLAGS_LEFT_JUSTIFY '-'
# define FLAGS_FILL_WITH_0 '0'
# define FLAGS_SIGN_OUTPUT '+'
# define FLAGS_POSITIVE_BLANK ' '
# define FLAGS_ALTERNATE_PRINT '#'
# define FLAGS_THOUSANDS_GROUPS '\''
# define FLEFT 0b10000000
# define FFIL0 0b01000000
# define FSIGN 0b00100000
# define FPOSI 0b00010000
# define FALTR 0b00001000
# define FTHOU 0b00000100

# define FIELD_WIDTH_PARAM_VALUE '*'

# define PRECISION_BEGIN '.'
# define PRECISION_PARAM_VALUE '*'

# define LENGTH_CHAR_INT "hh"
# define LENGTH_SHORT_INT 'h'
# define LENGTH_LONG_INT 'l'
# define LENGTH_LONG_LONG_INT "ll"
# define LENGTH_MAX_INT 'j'
# define LENGTH_PTRDIF 't'
# define LENGTH_SIZE_T 'z'
# define LENGTH_LONG_DOUBLE 'L'
# define LCHRI 0b10000000
# define LSHRI 0b01000000
# define LLONI 0b00100000
# define LLLOI 0b00010000
# define LMAXI 0b00001000
# define LPTRD 0b00000100
# define LSIZT 0b00000010
# define LLDOU 0b00000001

# define MODIFIERS "diouxXaAeEfFgGcs%"
# define INT_MODIFIERS "diouxX"
# define DOUBLE_MODIFIERS "aAeEfFgG"
# define ALPHA_MODIFIERS "cs"
# define CSINT 1
# define CUOCT 2
# define CUINT 3
# define CUMHX 4
# define CUHEX 5
# define CDMHX 6
# define CDHEX 7
# define CDMEX 8
# define CDEXP 9
# define CDDEC 10
# define CDMGE 11
# define CDGEN 12
# define CACHR 13
# define CASTR 14
# define CXXXX 42

typedef struct			s_part
{
	uint16_t			nu;
	uint8_t				flags;
	t_bool				width_p;
	uint32_t			width;
	t_bool				precision_p;
	uint32_t			precision;
	uint8_t				length;
	uint8_t				modifier;
}						t_part;

typedef struct			s_printf
{
	int					fd;
	char				*format;
	va_list				params;
	va_list				it_params;
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

t_bool					ft_compute_and_print_ph(t_printf *state);

void					*	

/*
** Modifiers
*/
void		ft_pf_str(t_printf *state);

#endif
