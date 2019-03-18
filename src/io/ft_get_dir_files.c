/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:23:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 20:02:20 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <stdlib.h>

t_bool				gdf_extension(struct dirent *dirent, const char *ext)
{
	const char		*ptr = dirent->d_name;

	while (*ptr && *ptr != '.')
	{
		ptr++;
	}
	ptr++;
	while (*ptr == *ext)
	{
		if (*ptr == '\0')
			return (TRUE);
		ptr++;
		ext++;
	}
	return (TRUE);
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
		if (dirent->d_type != DT_REG || (ext[0] != '\0'
					&& !gdf_extension(dirent, ext)))
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
