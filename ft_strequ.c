/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:44:54 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/15 17:39:37 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2) == 0);
	return (0);
}
