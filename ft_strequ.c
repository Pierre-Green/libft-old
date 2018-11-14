/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:44:54 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 18:09:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strnequ(s1, s2, ft_strlen(s1)));
	return (1);
}
