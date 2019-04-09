/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:27:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:28:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mem.h"

void					mlx_kill_pagination(t_pagination **pagination)
{
	mlx_kill_button(&(*pagination)->prev);
	mlx_kill_button(&(*pagination)->next);
}
