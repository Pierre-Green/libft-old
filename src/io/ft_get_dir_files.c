/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:20:08 by pierre            #+#    #+#             */
/*   Updated: 2019/02/22 13:56:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdlib.h>

t_bool				gdf_extension(struct dirent *dirent, const char *ext)
{
	const char		*ptr = ext;

	while (*ptr && *ptr != '.')
	{
		ptr++;
	}
	ptr++;
	while (*ptr == *ext)
	{
		if (*ptr == '\0')
			return (true);
		ptr++;
		ext++;
	}
	return (false);
}

t_dfiles			*ft_get_dir_files(DIR *dir, const char *ext, size_t *count)
{
	t_dfiles		*files;
	t_dfiles		*node;
	struct dirent	*dirent;

	if (!(files = (t_dfiles *)malloc(sizeof(t_dfiles))))
		return (NULL);
	node = files;
	node->file = NULL;
	*count = 0;
	while (((dirent = readdir(dir)) != NULL))
	{
		if ((ext[0] != '\0' && !gdf_extension(dirent, ext)) || dirent->d_type == DT_REG)
			continue ;
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
