/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:28:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 16:32:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_utils.h"

void				ft_put_uint_fd(uintmax_t i, int fd)
{
	ft_putl_uint_fd(i, fd, ft_count_digits_uint(i));
}
