/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:51:21 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/23 20:07:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_next_line(t_list **s_buff, char *overflow, size_t overflow_len)
{
	/* On cherche si il y a un \n dans overflow si oui on prend sa position */
	/* Si il n'y a pas eu de \n on copie overflow_len characteres de overflow dans s_buff->next */
	/* Si il a trouve un \n on copie overflow du debut jusqu'au \n inclut dans s_buff->next
	** puis on appelle recursivement:
	** ft_next_line(s_buff->next, overflow a partir du premier \n + 1, et comme longueure overflow_len - la longeur de s_buff->next->content)  
	*/
}

static size_t	ft_next_part(t_list **s_buff, size_t buff_len, char *part, size_t part_len)
{
	/* On cherche si il y a un \n dans part si oui on prend sa position */
	/* On concat s_buff et part jusq'au \n */
	/* Si il y a eu un \n on appelle la fonction recursive:
	** ft_next_line(buffer_static, overflow (a partir du charactere apres le \n), overflow_len) 
	*/
	/* On free part */
	/* Puis on retourne 0 si on a trouve un \n ou la taille du nouveau buffer_static */ 
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*s_buff[(long) INT_MAX + 1];
	t_list			*node;
	char			buff[BUFF_SIZE];
	int				read_res;
	size_t			read_len;

	if (!(read(fd, buff,0)) || line == NULL)
		return (RET_ERR);
	if (!(s_buff[fd]))
		s_buff[fd] = ft_lstnew(ft_strnew(BUFF_SIZE), BUFF_SIZE);
	read_res = 0;
	if (ft_strchr(s_buff[fd]->content, '\n') != NULL)
	{
		s_buff[fd]->content = ft_strsub(s_buff[fd]->content, 0, s_buff[fd]->content_size - 1);
		read_res = -1;
	}
	read_len = 0;
	while ((read_res != -1) && ((read_res = read(fd, buff, BUFF_SIZE)) > 0))
		if ((read_len = ft_next_part(s_buff, read_len, buff, read_res)) == 0)
			break ;
	if (read_len == RET_ERR || read_res == RET_ERR)
		return (RET_ERR);
	*line = (char *) malloc(sizeof(char) * s_buff[fd]->content_size + 1);
	ft_strncpy(*line, s_buff[fd]->content, s_buff[fd]->content_size);
	*line[s_buff[fd]->content_size] = '\0';
	if ((node = s_buff[fd]->next))
	{
		free(s_buff[fd]->content);
		free(s_buff[fd]);
		s_buff[fd] = node;
	}
	if (read_res == RET_DONE)
		return (RET_DONE);
	return (RET_OK);
}