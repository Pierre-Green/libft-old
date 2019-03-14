/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:36:58 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/14 02:47:24 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t		ft_len(t_buff **st_buff)
{
	ssize_t			len;
	t_buff			*node;

	node = (*st_buff);
	len = 0;
	while (node)
	{
		if (node->ptr_newl)
		{
			len += (node->ptr_newl - (char *)node->content);
			break ;
		}
		len += node->content_size;
		node = node->next;
	}
	return (len);
}

static ssize_t		ft_a_p(t_buff **st_bf, char *line, ssize_t current)
{
	char			*s;
	ssize_t			t;
	t_buff			*tmp;

	s = (char *)(*st_bf)->content;
	t = ((*st_bf)->ptr_newl ? ((*st_bf)->ptr_newl
		- (char *)(*st_bf)->content) : -1);
	ft_memmove(line + current, s, (t != -1 ? (size_t)t
				: (*st_bf)->content_size));
	if ((*st_bf)->ptr_newl)
	{
		(*st_bf)->content_size = (*st_bf)->content_size - t - 1;
		ft_memcpy((*st_bf)->content, s + t + 1, (*st_bf)->content_size);
		ft_bzero((char *)(*st_bf)->content + (*st_bf)->content_size,
			GNL_BUFF_SIZE - (*st_bf)->content_size);
		(*st_bf)->ptr_newl = ft_memchr((*st_bf)->content, '\n',
			(*st_bf)->content_size);
		return (-1);
	}
	tmp = (*st_bf);
	(*st_bf) = (*st_bf)->next;
	t = tmp->content_size;
	ft_memdel((void **)&tmp);
	return (current + t);
}

static ssize_t		ft_do_line(t_buff **st_bf, char **line)
{
	ssize_t			len;
	ssize_t			current;

	len = ft_len(st_bf);
	if (!(*line = malloc(len + 1)))
		return (GNL_RET_ERR);
	current = 0;
	while (*st_bf)
		if ((current = ft_a_p(st_bf, *line, current)) == -1)
			break ;
	(*line)[len] = '\0';
	return (len);
}

static t_buff		*i_buf(void)
{
	t_buff		*node;

	if (!(node = (t_buff *)malloc(sizeof(t_buff))))
		return (NULL);
	node->content_size = 0;
	node->ptr_newl = NULL;
	node->next = NULL;
	return (node);
}

int					get_next_line(const int fd, char **line)
{
	static t_buff	*s_bf[(unsigned long)INT_MAX + 1];
	t_buff			*node;
	char			buff[GNL_BUFF_SIZE];
	ssize_t			res[2];

	if (read(fd, buff, 0) < 0 || !line || (!s_bf[fd] && !(s_bf[fd] = i_buf())))
		return (GNL_RET_ERR);
	res[1] = 0;
	node = s_bf[fd];
	while (node && !(node->ptr_newl) && node->next)
		node = node->next;
	while (!(node->ptr_newl) && (res[0] = read(fd, buff, GNL_BUFF_SIZE)) > 0)
	{
		if (!(node->next = i_buf()))
			return (GNL_RET_ERR);
		ft_memcpy(node->content, buff, res[0]);
		node->content_size = res[0];
		node->ptr_newl = ft_memchr(node->content, '\n', res[0]);
		if (node->ptr_newl)
			break ;
		node = node->next;
	}
	if ((res[0] = ft_do_line(&s_bf[fd], line)) == (int)GNL_RET_ERR ||
		res[0] == GNL_RET_ERR || (int)res[1] == GNL_RET_ERR)
		return (GNL_RET_ERR);
	return (!s_bf[fd] && (*line)[0] == '\0' ? GNL_RET_DONE : GNL_RET_OK);
}
