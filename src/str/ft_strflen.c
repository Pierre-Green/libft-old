/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strflen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:24:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 18:32:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t					ft_strflen(const char *str)
{
	const char			*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}
