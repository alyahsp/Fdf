/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:25:58 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/19 18:40:33 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_funct(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(((t_env *)e)->mlx, ((t_env *)e)->win);
		exit(1);
	}
	// else if (keycode == 124)
	// {
	// 	e
	// }
	return (0);
}

void	draw_pixel(t_env e, int x, int y, int color)
{
	int		i;

	i = (e.sline * y) + (x * 4);
	e.addr[i] = color & 0xFF;
	e.addr[++i] = color >> 8 & 0xFF;
	e.addr[++i] = color >> 16;
}

void	put_persp(t_env e)
{
	int		l;
	int		c;

	l = 0;
	while (l < e.y_max)
	{
		c = 0;
		while (c < e.x_max)
		{
			e.coord[l][c].x = (sqrt(3) * c);
			e.coord[l][c].y = (1 * c + 2 * l + 1 * e.coord[l][c].z);
			// e.coord[l][c].z = sqrt(2) * c + (-sqrt(2) * l) + sqrt(2) * e.coord[l][c].z;
			printf("x = %d\n", e.coord[l][c].x);
			draw_pixel(e, e.coord[l][c].x * e.zoom, e.coord[l][c].y * e.zoom, 0xFFFFFF);
			c++;
		}
		l++;
	}
}

void	ft_drawmap(t_env e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 800, 800, "FdF");
	e.img = mlx_new_image(e.mlx, 800, 800);
	e.addr = mlx_get_data_addr(e.img, &e.bpp, &e.sline, &e.end);
	put_persp(e);
	// while (l < e.y_max)
	// {
	// 	c = 0;
	// 	while (c < e.x_max)
	// 	{
	// 		draw_pixel(e, c, l, 0xffffff);
	// 		c++;
	// 	}
	// 	l++;
	// }
	// printf("xmax  = %d y_max = %d", e.x_max, e.y_max);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 200, 200);
	mlx_destroy_image(e.mlx, e.img);
	mlx_key_hook(e.win, &key_funct, &e);
	mlx_loop(e.mlx);
}
