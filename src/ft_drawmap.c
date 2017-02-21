/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:25:58 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/21 21:55:10 by spalmaro         ###   ########.fr       */
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
	return (0);
}

void	draw_pixel(t_env e, int x, int y, int color)
{
	int		i;

	if (x >= 800 || y >= 800)
		ft_error(2);
	i = (e.sline * y) + (x * 4);
	e.addr[i] = color & 0xFF;
	e.addr[++i] = color >> 8 & 0xFF;
	e.addr[++i] = color >> 16;
}

void	draw(t_env e, int color)
{
	int		l;
	int		c;

	l = 0;
	while (l < e.y_max)
	{
		c = 0;
		while (c < e.x_max)
		{
			if (c + 1 < e.x_max)
				draw_linex(e, l, c, color);
			if (l + 1 < e.y_max)
				draw_liney(e, l, c, color);
			e.flag = 0;
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
	draw(e, 0xFFFFFF);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_destroy_image(e.mlx, e.img);
	mlx_key_hook(e.win, &key_funct, &e);
	mlx_loop(e.mlx);
}
