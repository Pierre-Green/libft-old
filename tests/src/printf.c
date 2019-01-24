/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:29:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/24 22:56:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_printf.h"
#include "ft_bool.h"
#include <stdint.h>
#include <stdarg.h>

static t_bool			test1()
{
	ft_printf("Ohyeyahh%\n", "bite", 31);
	return (true);
}

void			ft_printf_test()
{
	static		t_bool (*tests[])(void) = { test1  };
	uint16_t	score;
	uint16_t	length;
	uint8_t	current;

	current = 0;
	score = 0;
	length = sizeof(tests) / sizeof(*tests);
	printf("Starting printf tests... (%d to do)\n", length);
	while (current < length) 
	{
		if (tests[current]())
			score++;
		current++;
	}
	printf("Score: %d/%d\n", score, length);
}
