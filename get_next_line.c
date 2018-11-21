/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:03:05 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/21 13:44:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_overflow_add(t_list **buff, char *overflow, int count)
{
	t_list			*line;
	char			*tmp_ptr;
	int				len;

	line = *buff;
	tmp_ptr = overflow;
	while (*tmp_ptr != '\n' && *tmp_ptr != '\0')
		tmp_ptr++;
	if ((len = (tmp_ptr - overflow) * sizeof(char)) == 0)
		return ;
	if (*tmp_ptr == '\n')
		line->next = ft_lstnew(ft_strsub(overflow, 0, len + 1), len + 1);
	else
		line->next = ft_lstnew(ft_strsub(overflow, 0, len), BUFF_SIZE);
	line = line->next;
	if (*tmp_ptr == '\n')
	{
		line->content_size = 0;
		ft_overflow_add(&line, ft_strsub(overflow, len + 1, ft_strlen(overflow) - len), count + 1);
	}
}

static int			ft_use_part(t_list **buff, char *part, int current)
{
	char			tmp[(*buff)->content_size];
	char			*newline_ptr;
	int				toconcat;

	ft_strcpy(tmp, (char *)(*buff)->content);
	free((*buff)->content);
	toconcat = BUFF_SIZE;
	if ((newline_ptr = ft_strchr(part, '\n')) != NULL)
		if ((toconcat = ((newline_ptr - part) * sizeof(char))) == 0)
			return (0);
	if (!((*buff)->content = malloc((current + toconcat + 1) * sizeof(char))))
		return (-1);
	ft_strcpy((*buff)->content, tmp);
	ft_strcpy(((*buff)->content + current), ft_strsub(part, 0, toconcat));
	ft_overflow_add(buff, ft_strsub(part, toconcat + 1, BUFF_SIZE - toconcat), 1);
	(*buff)->content_size = current + toconcat + 1;
	return ((toconcat != BUFF_SIZE ? 0 : (*buff)->content_size - 1));
}

static t_list		*ft_get_buff_pos(t_list **buf)
{
	t_list			*buff;

	buff = *buf;
	if (buff && buff->next)
	{
		if (buff->next->content_size == 0)
			buff->next->content_size = ft_strlen(buff->next->content);
		return (buff->next);
	}
	else
		return(ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE));
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*buff[(long)INT_MAX + 1];
	char			t_buff[BUFF_SIZE];
	int				chr_count;
	int				read_res;

	buff[fd] = ft_get_buff_pos(&buff[fd]);
	if (buff[fd]->content_size == BUFF_SIZE)
	{
		chr_count = 0;
		while ((read_res = read(fd, t_buff, BUFF_SIZE)))
		{
			chr_count = ft_use_part(&buff[fd], t_buff, chr_count);
			if (chr_count == -1 || read_res == -1)
				return (RET_ERR);
			if (chr_count == 0)
				break;
		}
	}
	else
		read_res = (chr_count = ft_use_part(&buff[fd], (char *)buff[fd]->content, 0)) + 1;
	if (read_res == 0 || chr_count == 0)
	{
		if (!(*line = malloc(sizeof(char) * (buff[fd]->content_size))))
			return (RET_ERR);
		ft_strcpy(*line, buff[fd]->content);	
		if (read_res == 0)
			return (RET_DONE);
	}
	return (RET_OK);
}