/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:22:16 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/08 19:03:19 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 		*ft_strnew(size_t size)
{
	char	*res;
	if (!(res = (char *)ft_memalloc(size + 1)))
		return (NULL);
	ft_strclr(res);
	return (res);
}