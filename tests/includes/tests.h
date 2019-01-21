/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:37:55 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/21 18:02:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include "ft_bool.h"
# include <stdint.h>
#include <stdio.h>

typedef struct		s_mlx_state
{
	void			*mlx;
	void			*win;
	void			*cwin;
	void			(*curr_test)(struct s_mlx_state *);
}					t_mlx_state;

void	mlx_tests();

void	ft_mlx_test1(t_mlx_state *p_state);

void	ft_vec_tests();

void	ft_printf_test();

#endif
