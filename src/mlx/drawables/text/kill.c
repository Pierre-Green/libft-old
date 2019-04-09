/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:23:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:25:12 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mem.h"

void					mlx_kill_text(t_text **text)
{
	ft_memdel((void **)&(*text)->text);
	ft_memdel((void **)text);
}
