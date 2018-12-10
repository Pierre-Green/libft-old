/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:48:33 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/10 04:17:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*res;
	t_list			*tmp;
	t_list			*start;

	tmp = f(lst);
	if (!(res = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	start = res;
	while (lst)
	{
		tmp = f(lst);
		if (!(res->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (start);
}
