/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:55:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 20:55:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H
# include <stdlib.h>

typedef struct			s_param
{
	char				*value;
	struct s_param		*next;
}						t_param;

typedef struct			s_params
{
	t_param				*params;
	size_t				length;
	t_param				*(*at)(struct s_params *, size_t);
}						t_params;

t_params				*get_params(int argc, char **argv);

t_param					*at(t_params *params, size_t at);

#endif
