#ifndef FT_MLX_CONTAINER_H
# define FT_MLX_CONTAINER_H
# include "ft_math/point.h"
# include "ft_math/dim.h"
# include "ft_mlx/color.h"
# include "ft_mlx/drawable.h"

typedef struct		s_container
{
	t_drawable		**childs;
	int				(*draw)(struct s_container *, t_point2d, void *);
	t_color			background_color;
	t_dim2d			dim;
	t_point2d		pos;
}					t_container;

#endif
