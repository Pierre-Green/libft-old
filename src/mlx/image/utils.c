/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:47:09 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:39:12 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_image_carry			*ft_image_merge(t_drawable drawable, t_point2d offset,
		t_image_carry *carry)
{
	const t_drwble		obj = drawable.drawable;

	if (drawable.type == CONTAINER)
		obj.container->image(obj.container, offset, carry);
	if (drawable.type == BUTTON)
		obj.button->image(obj.button, offset, carry);
	if (drawable.type == PAGINATION)
		obj.pagination->image(obj.pagination, offset, carry);
	if (drawable.type == CANVAS)
		obj.canvas->image_intern(obj.canvas, offset, carry);
	return (carry);
}

size_t					mlx_image_offset(t_image_carry *img, size_t x, size_t y)
{
	return (((y * img->size_line) + (x * (img->bits_per_pixels / 8))));
}

void					ft_copy_pixel_to_image(t_image_carry *des, t_image_carry *src, t_point2d dest_pos, t_point2d src_pos)
{
	size_t				dest_offset;
	size_t				src_offset;

	dest_offset = mlx_image_offset(des, dest_pos.x, dest_pos.y);
	src_offset = mlx_image_offset(src, src_pos.x, src_pos.y);
	des->data[dest_offset] = src->data[src_offset]; 
	des->data[dest_offset + 1] = src->data[src_offset + 1]; 
	des->data[dest_offset + 2] = src->data[src_offset + 2];
}

void					ft_put_pixel_to_image(t_image_carry *carry, size_t x,
		size_t y, unsigned int color)
{
	size_t				offset;

	offset = mlx_image_offset(carry, x, y);
	carry->data[offset] = (color & 0xFF);
	carry->data[offset + 1] = (color & 0xFF00) >> 8;
	carry->data[offset + 2] = (color & 0xFF0000) >> 16;
}

t_image_carry				*ft_image_carry_from(void *img_ptr, char *addr,
		int bpp, int sizel, int endian)
{
	t_image_carry			*carry;

	if (!(carry = (t_image_carry *)malloc(sizeof(t_image_carry))))
		return (NULL);
	carry->img_ptr = img_ptr;
	carry->data = addr;
	carry->bits_per_pixels = bpp;
	carry->size_line = sizel;
	carry->endian = endian;
	return (carry);
}
