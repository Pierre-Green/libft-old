/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:02:39 by pierre            #+#    #+#             */
/*   Updated: 2019/02/10 20:05:48 by pierre           ###   ########.fr       */
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
