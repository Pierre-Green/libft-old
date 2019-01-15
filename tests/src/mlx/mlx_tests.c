/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:10:44 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 19:00:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ft_mem.h"
#include <mlx.h>

static t_mlx_state	*init_state()
{
	t_mlx_state		*state;

	if (!(state = ft_memalloc(sizeof(t_mlx_state))))
		return (NULL);
	state->mlx = NULL;
	state->win = NULL;
	state->cwin = NULL;
	state->curr_test = ft_mlx_test1;
	return (state);
}

int					render_loop(void *params)
{
	t_mlx_state		*state;

	state = (t_mlx_state *)params;
	mlx_clear_window(state->mlx, state->win);
	state->curr_test(state);
	return (42);
}

void				mlx_tests()
{
	t_mlx_state		*state;

	printf("Starting MLX tests...\n");
	state = init_state();
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, 1000, 500, "MLX tests");
	state->cwin = mlx_new_window(state->mlx, 200, 500, "MLX test controller");
	mlx_loop_hook(state->mlx, render_loop, (void *)state);
	mlx_loop(state->mlx);
}
