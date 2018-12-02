/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:23:52 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:14:41 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list		*ft_lstlast(t_list *begin_list)
{
	t_list	*node;

	if (begin_list)
	{
		node = begin_list;
		while (node->next)
			node = node->next;
		return (node);
	}
	return (NULL);
}
