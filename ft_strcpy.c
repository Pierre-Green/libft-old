/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:53 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/13 14:17:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*result;

	if ((result = (char *)ft_memcpy((void *)dest, (void *)src, ft_strlen(src))))
		result[ft_strlen(src)] = '\0';
	return (result);
}