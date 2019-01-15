/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:35:01 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 18:59:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <mlx.h>

void				ft_mlx_test1(t_mlx_state *state)
{
	uint8_t			curr;

	curr = 10;
	while (curr < 100)
	{
		mlx_pixel_put(state->mlx, state->win, curr, 10, 0xFF0000);
		curr++;
	}
}
