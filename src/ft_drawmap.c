/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:25:58 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/17 16:44:11 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_persp(t_env list, t_coord *coord)
{

}

void	draw_pixel(t_env list, int x, int y, int color)
{
	int		i;

	i = (list->sline * y) + (x * 4);
	list.addr[i] = color & 0xFF;
	list.addr[++i] = color >> 8 & 0xFF;
	list.addr[++i] = color >> 16;
}

void	ft_drawmap(t_env list, t_coord **coord)
{
	list.mlx = mlx_init();
	list.win = mlx_new_window(list.mlx, 800, 800, "FdF");
	list.img = mlx_new_image(list.mlx, 800, 800);
	list.addr = mlx_get_data_addr(list.img, &list.bpp, &list.sline, &list.end);
	put_persp(list, coord);
	while ((*coord)->y < list.ymax)
	{
		while ((*coord)->x < list.xmax && )
		draw_pixel(list, (*coord)->x, (*coord)->y, 0xFFFFFF);
		(*coord->y)++;
	}
	mlx_loop(list.mlx);
}
