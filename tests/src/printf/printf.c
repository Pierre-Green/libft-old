/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:29:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/29 16:39:11 by pguthaus         ###   ########.fr       */
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

static t_printf		*state()
{
	t_printf		*state;

	if (!(state = (t_printf *)ft_memalloc(sizeof(t_printf))))
		return (NULL);
	state->fd = 0;
	state->format = NULL;
	state->length = 0;
	return (state);
}

static t_bool			test1()
{
	ft_printf("Ohyeyahh%d\n", "bite", 31);
	return (true);
}

void			ft_printf_test()
{
	static		t_bool (*tests[])(t_printf *) = 
	{
				test1,
				ft_parameter_test,
				ft_flags_test,
				ft_width_test,
				ft_precision_test,
				ft_length_test
	};
	uint16_t	score;
	uint16_t	length;
	uint8_t		current;
	t_printf	*pf;

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
		ft_strdel(&pf->format);
		current++;
	}
	printf("ft_printf score: %d/%d\n", score, length);
}
