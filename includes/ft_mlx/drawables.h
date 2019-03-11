/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:14:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/11 20:00:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLE_H
# define FT_MLX_DRAWABLE_H
# include "ft_math/zone.h"
# include "ft_mlx/color.h"

# define OFFSET_NULL ({ 0, 0 })

typedef size_t			t_margin[4];

typedef enum			e_drawable_types
{
						CONTAINER,
						TEXT,
						BUTTON,
						PAGINATION,
						NONE
}						t_drawable_types;

typedef struct			s_image_carry
{
	void				*img_ptr;
	char				**data;
	int					bits_per_pixels;
	int					size_line;
	int					endian;
}						t_image_carry;

t_image_carry			*ft_image_carry_from(void *img_ptr, char **addr, int bpp, int sizel, int endian);

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
	int					uuid;
	char				*(*image)(struct s_button *, t_point2d, t_image_carry *);
	void				(*render_txt)(struct s_button *, t_point2d, void *);
	void				(*onclick)(int, int, void *);
	t_color				background_color;
	t_dim2d				dim;
	t_point2d			pos;
}						t_button;

typedef struct s_drawables	t_drawables;
typedef struct s_drawable	t_drawable;

typedef struct			s_container
{
	t_drawables			*childs;
	t_image_carry		*(*render)(struct s_container *, void *, void *, t_image_carry *);
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
	t_zone2d			zone;
	t_drawables			*items;
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

t_button				*mlx_init_button(t_point2d pos, t_dim2d dim, t_color color, char *text, int uuid);

void					mlx_button_background(t_button *button, t_point2d offset, t_image_carry *carry);

void					mlx_container_render_txt(t_container *container, t_point2d offset, void *win);

void					mlx_button_render_txt(t_button *button, t_point2d offset, void *win);

void					mlx_pagination_render_txt(t_pagination *pagination, t_point2d offset, void *win);

void					mlx_text_render_txt(t_text *text, t_point2d offset, void *win);

t_container				*ft_init_container(t_point2d pos, t_dim2d dim, t_color color);

t_image_carry			*mlx_container_render(t_container *container, void *mlx_ptr, void *win_ptr, t_image_carry *old);

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

size_t					mlx_text_width(char *str);

#endif
