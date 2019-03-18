/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:14:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 18:34:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLE_H
# define FT_MLX_DRAWABLE_H
# include "ft_math/zone.h"
# include "ft_mlx/color.h"
# include "ft_mlx/image.h"
# include "ft_mlx/canvas.h"
# define OFFSET_NULL ({ 0, 0 })
# define MLX_CHAR_WIDTH 10
# define MLX_CHAR_HEIGHT 20
# define MLX_PAGINATION_BOT_SIZE 70
# define MLX_PAGINATION_ACTION_PREV 21
# define MLX_PAGINATION_ACTION_NEXT 42

typedef size_t			t_margin[4];

typedef enum			e_drawable_types
{
						CONTAINER,
						TEXT,
						BUTTON,
						PAGINATION,
						CANVAS,
						NONE
}						t_drawable_types;

typedef enum			e_alignement
{
						LEFT,
						CENTER,
						RIGHT
}						t_alignement;

typedef struct			s_text
{
	char				*text;
	void				(*render_txt)(struct s_text *, t_point2d, void *);
	t_alignement		align;
	t_color				color;
	t_point2d			pos;
}						t_text;

typedef struct			s_button
{
	t_text				*text;
	void				*s;
	int					uuid;
	char				*(*image)(struct s_button *, t_point2d, t_image_carry *);
	void				(*render_txt)(struct s_button *, t_point2d, void *);
	void				(*onclick)(int, int, void *);
	t_color				background_color;
	t_color				disabled_background_color;
	t_bool				enabled;
	t_dim2d				dim;
	t_point2d			pos;
}						t_button;


typedef struct s_drawables	t_drawables;
typedef struct s_drawable	t_drawable;

typedef struct			s_container
{
	t_drawables			*childs;
	t_image_carry		*(*render)(struct s_container *, void *, t_image_carry *);
	void				(*render_txt)(struct s_container *, t_point2d, void *);
	char				*(*image)(struct s_container *, t_point2d, t_image_carry *);
	void				(*add_child)(struct s_container *, t_drawable *);
	t_color				background_color;
	t_dim2d				dim;
	t_point2d			pos;
}						t_container;

typedef struct			s_pagination
{
	char				*(*image)(struct s_pagination *, t_point2d, t_image_carry *);
	void				(*render_txt)(struct s_pagination *, t_point2d, void *);
	void				(*add_child)(struct s_pagination *, t_drawable *);
	t_button			*prev;
	t_button			*next;
	t_zone2d			zone;
	t_drawables			*items;
	t_dim2d				gride;
	size_t				page;
	size_t				items_count;
	t_dim2d				items_dim;
	t_margin			items_margin;
}						t_pagination;

t_pagination			*mlx_init_pagination(t_zone2d zone, t_dim2d items_dim, t_margin items_margin);

char					*mlx_pagination_image(t_pagination *self, t_point2d offset, t_image_carry *carry);

typedef union			u_drwble
{
	t_container			*container;
	t_text				*text;
	t_button			*button;
	t_pagination		*pagination;
	t_canvas			*canvas;
}						t_drwble;

typedef struct			s_drawable
{
	t_drwble			drawable;
	t_drawable_types	type;
}						t_drawable;

t_drawable				*ft_init_drawable(t_drawable_types type, void *value);

typedef struct			s_drawables
{
	t_drawable			*drawable;
	struct s_drawables	*next;
}						t_drawables;


t_text					*ft_init_text(t_point2d pos, char *text, t_color color);

t_button				*mlx_init_button(t_point2d pos, t_dim2d dim, t_color color, char *text);

void					mlx_button_background(t_button *button, t_point2d offset, t_image_carry *carry);

void					mlx_container_render_txt(t_container *container, t_point2d offset, void *win);

void					mlx_button_render_txt(t_button *button, t_point2d offset, void *win);

void					mlx_pagination_render_txt(t_pagination *pagination, t_point2d offset, void *win);

void					mlx_text_render_txt(t_text *text, t_point2d offset, void *win);

t_container				*ft_init_container(t_point2d pos, t_dim2d dim, t_color color);

t_image_carry			*mlx_container_render(t_container *container,void *win, t_image_carry *old);

t_drawable				*mlx_container_to_drawable(t_container *container);

void					mlx_container_background(t_container *c, t_point2d o, t_image_carry *carry);

void					ft_add_drawable_to_drawables(t_drawables *dest, t_drawable *src);

int						ft_drawable_routerender(t_drawable drawable, t_point2d offset, void *);

t_image_carry			*ft_image_merge(t_drawable *drawable, t_point2d offset, t_image_carry *carry);

t_image_carry			*ft_image_router(t_drawable *drawable, t_image_carry *dest);

void					ft_put_pixel_to_image(t_image_carry *carry, size_t x, size_t y, unsigned int color);

t_drawable				*ft_drawable_at(t_drawables *lst, size_t i);

t_point2d				mlx_pagination_offset(t_pagination *pagination, t_point2d offset, t_zone2d gride, t_bool center);

t_dim2d					mlx_pagination_gride_dims(t_pagination *pagination);

char					*mlx_container_image(t_container *self, t_point2d offset, t_image_carry *carry);

size_t					mlx_text_width(char *str);

char					*mlx_button_image(t_button *self, t_point2d offset, t_image_carry *carry);

void					mlx_container_add_child(t_container *self, t_drawable *drawable);

void					mlx_pagination_add_item(t_pagination *self, t_drawable *drawable);
#endif
