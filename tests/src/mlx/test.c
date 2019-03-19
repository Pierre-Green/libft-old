/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pguthaus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 02:54:16 by pierre            #+#    #+#             */
/*   Updated: 2019/03/19 17:10:11 by pguthaus         ###   ########.fr       */
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
	t_container			*page;
	t_container			*header;
	t_container			*body;
	t_pagination		*pagination;
	t_button			*button;
	char				c;
	char				*str;

	page = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT), 0xF2F4F8);
	header = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT / 3), 0x000000);
	body = ft_init_container(POS(0, WIN_HEIGHT / 3), DIM(WIN_WIDTH, WIN_HEIGHT - WIN_HEIGHT / 3), 0x0000FF);
	pagination = mlx_init_pagination(ft_zone2d_from_pdim(POS(0, 0),
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
	page->add_child(page, ft_init_drawable(CONTAINER, header));
	page->add_child(page, ft_init_drawable(CONTAINER, body));
	body->add_child(body, ft_init_drawable(PAGINATION, pagination));
	return (page);
}

static t_image_carry	*canvas_img(t_canvas *canvas, void *s, t_image_carry *img)
{
	size_t				x;
	size_t				y;

	y = 0;
	while (y < 50)
	{
		x = 5;
		while (x < 78)
		{
			ft_put_pixel_to_image(img, x, y, 0xF4369D);
			x++;
		}
		y++;
	}
	return (img);
}

static t_container		*body2()
{
	t_container			*page;
	t_canvas			*canvas;

	page = ft_init_container(POS(0, 0), DIM(WIN_WIDTH, WIN_HEIGHT), 0xFF12FF);
	canvas = mlx_init_canvas(POS(100, 100), DIM(100, 200));
	canvas->image = canvas_img;

	page->add_child(page, ft_init_drawable(CANVAS, canvas));
	return (page);
}
void					ft_mlx_tests()
{
	void				*mlx_ptr;
	t_window			*window;
	t_window			*window2;

	mlx_ptr = mlx_init();
	window = ft_init_window(mlx_ptr, DIM(WIN_WIDTH, WIN_HEIGHT), "MLX tests", (void *)0);
	window->body = body();
	window->render(window);
	window2 = ft_init_window(mlx_ptr, DIM(WIN_WIDTH, WIN_HEIGHT), "MLX canvas tests", NULL);
	window2->body = body2();
	window2->render(window2);
	mlx_loop(mlx_ptr);
}
