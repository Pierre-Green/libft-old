/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:38:34 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 18:05:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ft_math/vec.h"

/*
** Minus checker
*/
static t_bool			test1()
{
	t_vec3_d	vec3_d1;
	t_vec3_d	vec3_d2;
	t_vec3_d	res;

	vec3_d1	= ft_init3_vec3_d(23.4, 563.52, 4345.23342);
	vec3_d2	= ft_init3_vec3_d(2.4, 53.52, 445.2342);
	res = ft_vec3_d_minus(vec3_d1, vec3_d2);
	if ((res.x == (vec3_d1.x - vec3_d2.x)) && (res.y == (vec3_d1.y - vec3_d2.y)) && (res.z == (vec3_d1.z - vec3_d2.z)))
		return (TRUE);
	return (FALSE);
}

/*
** Normalize checker
*/
static t_bool			test2()
{
	t_vec3_ld	vec;

	vec = ft_init3_vec3_ld(34, 21, -54);
	vec = ft_vec3_ld_normalize(vec);
	printf("%Lf %Lf %Lf\n", vec.x, vec.y, vec.z);
	return (TRUE);
}

void			ft_vec_tests()
{
	static		t_bool (*tests[])(void) = { test1, test2 };
	uint8_t		current;
	uint16_t	score;
	uint16_t	length;

	current = 0;
	score = 0;
	length = sizeof(tests) / sizeof(*tests);
	printf("Starting vector tests... (%d to do)\n", length);
	while (current < length) 
	{
		if (tests[current]())
			score++;
		current++;
	}
	printf("Score: %d/%d\n", score, length);
}
