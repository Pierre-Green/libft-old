/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pguthaus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 02:54:16 by pierre            #+#    #+#             */
/*   Updated: 2019/03/14 03:25:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tests.h"

static t_container		*body()
{
	t_container			*body;
	t_container			*header;

	body = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT), 0xF2F4F8);
	header = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT / 3), 0x000000);
	body->add_child(body, ft_init_drawable(CONTAINER, header));
	return (body);
}

void					ft_mlx_tests()
{
	void				*mlx_ptr;
	t_window			*window;

	mlx_ptr = mlx_init();
	window = ft_init_window(mlx_ptr, DIM(WIN_WIDTH, WIN_HEIGHT), "MLX tests", (void *)0);
	window->body = body();
	window->render(window);
	mlx_loop(mlx_ptr);
}
