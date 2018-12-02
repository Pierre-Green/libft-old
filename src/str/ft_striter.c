/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:04:16 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:22:41 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	current;

	if (s && f)
	{
		current = 0;
		while (s[current])
		{
			f(&s[current]);
			current++;
		}
	}
}
