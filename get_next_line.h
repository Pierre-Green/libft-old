/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:01:40 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/22 15:43:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# define BUFF_SIZE 32
# define RET_OK 1
# define RET_DONE 0
# define RET_ERR -1

int		get_next_line(const int fd, char **line);

#endif