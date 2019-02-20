/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:11:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 22:18:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"

t_param					*at(t_params *params, size_t at)
{
	t_param				*node;
	size_t				current;

	if (at >= params->length)
		return (NULL);
	node = params->params;
	current = 0;
	while (current < at)
	{
		node = node->next;
		current++;
	}
	return (node);
}
