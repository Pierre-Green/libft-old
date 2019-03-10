/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:01:40 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/10 01:04:45 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include "ft_mem.h"
# include "ft_io.h"
# define GNL_BUFF_SIZE 256
# define GNL_RET_OK 1
# define GNL_RET_DONE 0
# define GNL_RET_ERR -1

typedef struct		s_buff
{
	char			content[GNL_BUFF_SIZE];
	char			*ptr_newl;
	size_t			content_size;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
