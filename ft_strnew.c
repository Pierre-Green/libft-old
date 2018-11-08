/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:22:16 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/08 18:24:48 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *  	ft_strnew(size_t size)
{
	char	*res;
	size_t	current;

	if (!(res = (char *)malloc((1 + size) * sizeof(char))))
		return (NULL);
	current = -1;
	while (++current <= size)
		res[current] = '\0';
	return (res);
}