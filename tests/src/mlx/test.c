/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pguthaus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 02:54:16 by pierre            #+#    #+#             */
/*   Updated: 2019/03/14 18:27:01 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tests.h"
#include "ft_str.h"
#include "ft_printf.h"

static void				onclick(int mouse, int target, void *s)
{
	ft_printf("%c\n", target);
	(void)s;
	(void)mouse;
}

static t_container		*body()
{
	t_container			*body;
	t_container			*header;
	t_pagination		*pagination;
	t_button			*button;
	char				c;
	char				*str;

	body = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT), 0xF2F4F8);
	header = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT / 3), 0x000000);
	pagination = mlx_init_pagination(ft_zone2d_from_pdim(POS(0, WIN_HEIGHT / 3),
			DIM(WIN_WIDTH, WIN_HEIGHT - WIN_HEIGHT / 3)), DIM(100, 50),
			(t_margin){10, 10, 10, 10});
	c = 'A';
	while (c <= 'Z')
	{
		str = ft_strnew(1);
		str[0] = c;
		button = mlx_init_button(POS(0, 0), DIM(100, 50), 0x000000, str);
		button->uuid = c;
		button->onclick = onclick;
		pagination->add_child(pagination, ft_init_drawable(BUTTON, button));
		c++;
	}
	body->add_child(body, ft_init_drawable(CONTAINER, header));
	body->add_child(body, ft_init_drawable(PAGINATION, pagination));
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
