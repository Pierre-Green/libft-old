/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:20:08 by pierre            #+#    #+#             */
/*   Updated: 2019/02/22 13:37:19 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdlib.h>

t_dfiles			*ft_get_dir_files(DIR *dir, size_t *count)
{
	t_dfiles		*files;
	t_dfiles		*node;
	struct dirent	*dirent;

	if (!(files = (t_dfiles *)malloc(sizeof(t_dfiles))))
		return (NULL);
	node = files;
	node->file = NULL;
	*count = 0;
	while (((dirent = readdir(dir)) != NULL) && dirent->d_type == DT_REG)
	{
		if (node->file == NULL)
		{
			node->file = dirent;
			node->next = NULL;
		}
		else
		{
			node->next = (t_dfiles *)malloc(sizeof(t_dfiles));
			node->next->file = dirent;
			node->next->next = NULL;
			node = node->next;
		}
		(*count)++;
	}
	return (files);
}
