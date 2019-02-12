/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:29:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/12 18:42:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_printf.h"
#include "ft_bool.h"
#include <stdint.h>
#include <stdarg.h>
#include "tests.h"
#include "ft_mem.h"
#include "ft_str.h"
#include <wchar.h>
#include "ft_utils.h"
#include <locale.h>
#include <float.h>

static t_printf			*state()
{
	t_printf			*state;

	if (!(state = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (NULL);
	state->fd = 0;
	state->format = NULL;
	state->length = 0;
	return (state);
}

static t_bool			test1(t_printf *pf)
{
	// ft_printf("Ohyeyahh%2$-d\n", "bite", 31);
	pf->format = ft_strnew(10);
	ft_strcpy(pf->format, "%12$-#10.4h%");
	ft_print_ph(pf);
	printf("Param: %u, Flags: %u, Width: %u, Precision: %u, Length: %u, Converstion: %u\n", pf->part.nu, pf->part.flags, pf->part.width, pf->part.precision, pf->part.length, pf->part.modifier);
	return (true);
}

static t_bool			teststring()
{
	printf("BS: Say %-10s !\n", "bonjour");
	ft_printf("My: Say %-10s !\n\n", "bonjour");
	return (true);
}

static t_bool			testchar()
{
	const wchar_t		wc = L'\x3b1';
	setlocale(LC_ALL, "en_US.UTF-8");

	printf("BS: Char %6c .\n", 'A');
	ft_printf("My: Char %6c .\n", 'A');
	printf("BS: Wide Char %1C.\n", wc);
	ft_printf("My: Wide Char %1C.\n\n", wc);
	return (true);
}

static t_bool			testsignedint()
{
	signed char			c;

	c = 'a';
	printf("BS: INT: %1$10.6d str: %3$s str: %2$s.\n", -21, "yess", "hoy");
	ft_printf("My: INT: %10.6d str: %3$s str: %2$s.\n", -21, "yess", "hoy");
	printf("BS: INT: % 5d.\n", 213456);
	ft_printf("My: INT: % 5d.\n", -213456);
	printf("BS: INT: %0+10d.\n", 213456);
	ft_printf("My: INT: %0+10d.\n", 213456);
	printf("BS: INT: %hhd.\n", c);
	ft_printf("My: INT: %hhd.\n\n", c);
	return (true);
}

static t_bool			testunsignedoctal()
{
	printf("BS: Unsigned Octal %o\n", 13452);
	ft_printf("My: Unsigned Octal %o\n", 13452);
	printf("BS: Unsigned Octal %-#o\n", 1);
	ft_printf("My: Unsigned Octal %-#o\n", 1);
	printf("BS: Unsigned Octal %010o\n", 1234123);
	ft_printf("My: Unsigned Octal %010o\n\n", 1234123);
	return (true);
}

static t_bool			testunsignedecimal()
{
	printf("BS: Unsigned Decimal %llu\n", UINTMAX_MAX);
	ft_printf("My: Unsigned Decimal %llu\n\n", UINTMAX_MAX);
	return (true);
}

static t_bool			testunsignedhexa()
{
	printf("BS: Unsigned hexadecimal %x\n", 1231);
	ft_printf("My: Unsigned hexadecimal %x\n", 1231);
	printf("BS: Unsigned hexadecimal %#X\n", 123987);
	ft_printf("My: Unsigned hexadecimal %#X\n\n", 123987);
	return (true);
}

static t_bool			tesfloatfloat()
{
	printf("BS: Double %f\n", 1223.342);
	ft_printf("BS: Double %f\n", 1223.342);
	// printf("BS: Long double Max %Lf, %zu\n", LDBL_MAX, sizeof(LDBL_MAX));
	return (true);
}

void					ft_printf_test()
{
	static t_bool 		(*tests[])(t_printf *) = 
	{
//						test1,
						teststring,
						testchar,
						testsignedint,
						testunsignedoctal,
						testunsignedecimal,
						testunsignedhexa,
						tesfloatfloat,
						ft_parameter_test,
						ft_flags_test,
						ft_width_test,
						ft_precision_test,
						ft_length_test
	};
	uint16_t			score;
	uint16_t			length;
	uint8_t				current;
	t_printf			*pf;

	pf = state();
	current = 0;
	score = 0;
	length = sizeof(tests) / sizeof(*tests);
	printf("Starting printf tests... (%d to do)\n\n", length);
	while (current < length) 
	{
		if (tests[current](pf))
			score++;
		else
			printf("Failed test %d\n\n", current + 1);
		current++;
	}
	printf("ft_printf score: %d/%d\n", score, length);
}
