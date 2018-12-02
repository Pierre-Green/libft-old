/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:27:53 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:47:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list					*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	t_list				*node;
	unsigned int		current;

	if (begin_list)
	{
		node = begin_list;
		current = 0;
		while (node)
		{
			if (current == nbr)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}
