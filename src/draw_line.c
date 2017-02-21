/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:57:42 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/21 22:18:45 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check(t_env e, int l, int c)
{
	if (e.flag == 1)
	{
		if (e.xtmp == e.pts[l][c + 1].x && e.ytmp == e.pts[l][c + 1].y)
			return (0);
	}
	if (e.flag == 2)
	{
		if (e.xtmp == e.pts[l + 1][c].x && e.ytmp == e.pts[l + 1][c].y)
			return (0);
	}
	return (1);
}

void	just_doit(t_env e, int l, int c, int color)
{
	int	err;
	int e2;

	err = (e.dx > e.dy ? e.dx : -e.dy) / 2;
	e.xtmp = e.pts[l][c].x;
	e.ytmp = e.pts[l][c].y;
	while (1)
	{
		draw_pixel(e, e.xtmp, e.ytmp, 0xFFFFFF);
		if (!check(e, l, c))
			break ;
		e2 = err;
		if (e2 > -e.dx)
		{
			err -= e.dy;
			e.xtmp += e.xinc;
		}
		if (e2 < e.dy)
		{
			err += e.dx;
			e.ytmp += e.yinc;
		}
	}
}

void	draw_linex(t_env e, int l, int c, int color)
{
	e.dx = abs(e.pts[l][c + 1].x - e.pts[l][c].x);
	e.xinc = (e.pts[l][c + 1].x > e.pts[l][c].x) ? 1 : -1;
	e.dy = abs(e.pts[l][c + 1].y - e.pts[l][c].y);
	e.yinc = (e.pts[l][c + 1].y > e.pts[l][c].y) ? 1 : -1;
	e.flag = 1;
	just_doit(e, l, c, color);
}

void	draw_liney(t_env e, int l, int c, int color)
{
	e.dx = abs(e.pts[l + 1][c].x - e.pts[l][c].x);
	e.xinc = (e.pts[l + 1][c].x > e.pts[l][c].x) ? 1 : -1;
	e.dy = abs(e.pts[l + 1][c].y - e.pts[l][c].y);
	e.yinc = (e.pts[l + 1][c].y > e.pts[l][c].y) ? 1 : -1;
	e.flag = 2;
	just_doit(e, l, c, color);
}
