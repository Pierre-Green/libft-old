/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:15:04 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:14:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list		*ft_lstfold(t_list **lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*tmp;

	if (lst && *lst)
	{
		node = *lst;
		while (node)
		{
			tmp = f(node);
			node->content = tmp->content;
			node->content_size = tmp->content_size;
			node = node->next;
		}
	}
	return (*lst);
}
