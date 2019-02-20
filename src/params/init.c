/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:59:47 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 20:26:41 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_params.h"
# include "ft_str.h"

t_params				*get_params(int argc, char **argv)
{
	t_params			*params;
	t_param				*tmp;
	size_t				current;

	if (!(params = (t_params *)malloc(sizeof(t_params))) || argc == 0)
		return (NULL);
	if (!(params->params = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	params->length = (size_t) argc - 1;
	current = 1;
	tmp = params->params;
	while (current < (size_t) argc)
	{
		tmp->value = ft_strdup(argv[current]);
		current++;
		if (current != (size_t) argc)
		{
			if (!(tmp->next = (t_param *)malloc(sizeof(t_param))))
				return (NULL);
			tmp = tmp->next;
		}
	}
	params->at = at;
	return (params);
}
