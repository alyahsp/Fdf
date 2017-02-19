#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_coord
{
	int		x;
	int		y;
	int		z;
}					t_coord;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			sline;
	int			end;
	t_coord		**coord;
	int			y_max;
	int			x_max;
	int			zoom;
}					t_env;

void		ft_parsemap(int fd, t_env *e);
void		ft_error(int i);
void		ft_drawmap(t_env e);
#endif
