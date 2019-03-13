/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:28:35 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:28:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"

size_t		ft_wchar_length(wchar_t wc)
{
	if ((unsigned)wc < 0x80)
		return (1);
	else if ((unsigned)wc < 0x800)
		return (2);
	else if ((unsigned)wc < 0xd800 || (unsigned)wc - 0xe000 < 0x2000)
		return (3);
	else if ((unsigned)wc - 0x10000 < 0x100000)
		return (4);
	return (0);
}
