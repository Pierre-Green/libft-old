/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:19:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 18:20:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_IMAGE_H
# define FT_MLX_IMAGE_H

typedef struct			s_image_carry
{
	void				*img_ptr;
	char				**data;
	int					bits_per_pixels;
	int					size_line;
	int					endian;
}						t_image_carry;

t_image_carry			*ft_image_carry_from(void *img_ptr, char **addr, int bpp, int sizel, int endian);

#endif
