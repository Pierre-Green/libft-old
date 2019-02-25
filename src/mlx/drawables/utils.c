/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:30:16 by pierre            #+#    #+#             */
/*   Updated: 2019/02/25 15:02:12 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void						ft_add_drawable_to_drawables(t_drawables *dest, t_drawable *src)
{
	t_drawables				*node;

	node = dest;
	while (node->next)
		node = node->next;
	if (node->drawable == NULL)
		node->drawable = src;
	else
	{
		node->next = (t_drawables *)malloc(sizeof(t_drawables));
		node->next->drawable = src;
		node->next->next = NULL;
	}
}

t_image_carry				*ft_image_carry_from(char **addr, int bpp, int sizel, int endian)
{
	t_image_carry			*carry;

	if (!(carry = (t_image_carry *)malloc(sizeof(t_image_carry))))
		return (NULL);
	carry->data = addr;
	carry->bits_per_pixels = bpp;
	carry->size_line = sizel;
	carry->endian = endian;
	return (carry);
}
