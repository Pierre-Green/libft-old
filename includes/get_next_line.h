/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:01:40 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/10 04:17:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include "ft_mem.h"
# include "ft_io.h"
# define BUFF_SIZE 32
# define RET_OK 1
# define RET_DONE 0
# define RET_ERR -1

typedef struct		s_buff
{
	char			content[BUFF_SIZE];
	char			*ptr_newl;
	size_t			content_size;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(const int fd, char **line);

#endif
