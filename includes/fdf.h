#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_env
{
	int		y_max;
	int		x_max;
	int		**map;
}					t_env;

void		ft_parsemap(int fd, t_env dstruct);
void		ft_error(int i);
#endif
