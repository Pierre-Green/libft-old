/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prev_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:03:05 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/23 18:51:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_overflow_add(t_list **buff, char *overflow, size_t overflow_len)
{
	t_list			*line;
	char			*tmp_ptr;
	int				len;

	line = *buff;
	tmp_ptr = overflow;
	while (*tmp_ptr != '\n' && *tmp_ptr)
		tmp_ptr++;
	if ((len = (tmp_ptr - overflow) * sizeof(char)) == 0)
	{
		if (*tmp_ptr == '\n')
		{
			line->next = ft_lstnew((const char *)"", 0);
			ft_overflow_add(&line->next, overflow + 1 ,overflow_len - 1);
		}
		return ;
	}
	if (*tmp_ptr == '\n')
		line->next = ft_lstnew(ft_strsub(overflow, 0, len + 1), len + 1);
	else
		line->next = ft_lstnew(ft_strsub(overflow, 0, len), BUFF_SIZE);
	line = line->next;
	line->content = ft_strjoin(line->content, "\0");
	if (*tmp_ptr == '\n')
	{
		line->content_size = 0;
		ft_overflow_add(&line, ft_strsub(overflow, len + 1, overflow_len - len), overflow_len - len);
	}
}

static int			ft_use_part(t_list **buff, char *part, int current, size_t part_len)
{
	char			tmp[(*buff)->content_size];
	char			*newline_ptr;
	int				toconcat;

	ft_strcpy(tmp, (char *)(*buff)->content);
	free((*buff)->content);
	toconcat = part_len;
	if ((newline_ptr = ft_strchr(part, '\n')) != NULL)
		toconcat = (newline_ptr - part) * sizeof(char);
	if (!((*buff)->content = malloc((current + toconcat + 1) * sizeof(char))))
		return (-1);
	ft_strcpy((*buff)->content, tmp);
	ft_strcpy(((*buff)->content + current), ft_strsub(part, 0, toconcat));
	ft_overflow_add(buff, ft_strsub(part, toconcat + 1, part_len - toconcat), part_len - toconcat);
	(*buff)->content_size = current + toconcat + 1;
	return (((size_t)toconcat != part_len ? 0 : (*buff)->content_size - 1));
}

static t_list		*ft_get_buff_pos(t_list **buf)
{
	t_list			*buff;

	buff = *buf;
	if (buff && buff->next)
	{
		buff = buff->next;
		if (buff->content_size == 0)
			buff->content_size = ft_strlen(buff->content);
		free((*buf)->content);
		free(*buf);
		return (buff);
	}
	else
		return (ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE));
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*buff[(long)INT_MAX + 1];
	char			t_buff[BUFF_SIZE + 1];
	int				chr_count;
	int				read_res;

	if ((read(fd, t_buff, 0) == -1))
		return (RET_ERR);
	buff[fd] = ft_get_buff_pos(&buff[fd]);
	if (buff[fd]->content_size == BUFF_SIZE)
	{
		chr_count = ft_strlen(buff[fd]->content);
		while ((read_res = read(fd, t_buff, BUFF_SIZE)))
		{
			t_buff[read_res] = '\0';
			chr_count = ft_use_part(&buff[fd], t_buff, chr_count, read_res);
			if (chr_count == -1 || read_res == -1)
				return (RET_ERR);
			if (chr_count == 0)
				break ;
		}
	}
	else
		read_res = (chr_count = ft_use_part(&buff[fd], (char *)buff[fd]->content, 0, buff[fd]->content_size)) + 1;
	if (read_res == 0 || chr_count == 0)
	{
		if (!(*line = malloc(sizeof(char) * (buff[fd]->content_size))))
			return (RET_ERR);
		ft_strcpy(*line, buff[fd]->content);
		if (read_res == 0 && chr_count == 0)
			return (RET_DONE);
	}
	return (RET_OK);
}
