/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:21:07 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/15 20:26:48 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int	current;

	if (begin_list)
	{
		current = 0;
		while (begin_list)
		{
			current++;
			begin_list = begin_list->next;
		}
		return (current);
	}
	return (0);
}
