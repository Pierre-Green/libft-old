/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:24 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:26:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mem.h"

void					mlx_kill_button(t_button **button)
{
	ft_memdel((void **)&(*button)->text);
	ft_memdel((void **)button);
}
