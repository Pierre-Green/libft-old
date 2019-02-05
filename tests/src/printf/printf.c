/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:29:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 16:32:03 by pguthaus         ###   ########.fr       */
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
	printf("BS: Say %-10.3s !\n", "bonjour");
	ft_printf("My: Say %-10.3s !\n", "bonjour");
	return (true);
}

static t_bool			testchar()
{
	printf("digit %zu\n\n", ft_count_digits_intmax(12231231));
	const wchar_t		wc = L'\x3b1';
	setlocale(LC_ALL, "en_US.UTF-8");

	printf("BS: Char %6c .\n", 'A');
	ft_printf("My: Char %6c .\n", 'A');
	printf("BS: Wide Char %-6C .\n", wc);
	ft_printf("My: Wide Char %-6C .\n", wc);
	return (true);
}

void					ft_printf_test()
{
	static t_bool 		(*tests[])(t_printf *) = 
	{
//						test1,
						teststring,
						testchar,
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