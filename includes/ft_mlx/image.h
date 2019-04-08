/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:19:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:05:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_IMAGE_H
# define FT_MLX_IMAGE_H
# include <stdlib.h>
# include "ft_math/point.h"

typedef struct			s_image_carry
{
	void				*img_ptr;
	char				*data;
	int					bits_per_pixels;
	int					size_line;
	int					endian;
}						t_image_carry;

t_image_carry			*ft_image_carry_from(void *img_ptr, char *addr,
		int bpp, int sizel, int endian);

void					ft_put_pixel_to_image(t_image_carry *carry,
		size_t x, size_t y, unsigned int color);

void					ft_copy_pixel_to_image(t_image_carry *des,
		t_image_carry *src, t_point2d dest_pos, t_point2d src_pos);

size_t					mlx_image_offset(t_image_carry *img,
		size_t x, size_t y);

void					mlx_kill_image_carry(t_image_carry *self,
		void *mlx_ptr);

#endif
