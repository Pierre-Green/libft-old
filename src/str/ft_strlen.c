/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:21 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:23:35 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t		ft_strlen(const char *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
