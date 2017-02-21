/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:38:51 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/21 22:18:05 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct	s_pts
{
	int		x;
	int		y;
	int		z;
}				t_pts;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			sline;
	int			end;
	t_pts		**pts;
	int			y_max;
	int			x_max;
	int			z;
	int			height;
	int			xpos;
	int			ypos;
	int			xinc;
	int			yinc;
	int			dx;
	int			dy;
	int			flag;
	int			xtmp;
	int			ytmp;
}				t_env;

void			ft_parsemap(int fd, t_env *e);
void			ft_error(int i);
void			ft_drawmap(t_env e);
void			draw_linex(t_env e, int l, int c, int color);
void			draw_liney(t_env e, int l, int c, int color);
void			draw_pixel(t_env e, int x, int y, int color);
#endif
