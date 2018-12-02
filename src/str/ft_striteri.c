/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:07:42 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:22:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	current;

	if (s && f)
	{
		current = 0;
		while (s[current])
		{
			f(current, &s[current]);
			current++;
		}
	}
}
