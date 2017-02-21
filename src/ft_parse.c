/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:52 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/21 22:18:54 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_putintab(char *mapster, t_env *e, int i, int y)
{
	int		x;

	while (mapster[i] && (y < e->y_max))
	{
		if (!(e->pts[y] = (t_pts *)malloc(sizeof(t_pts) * e->x_max)))
			ft_error(1);
		x = 0;
		while (x < e->x_max)
		{
			if (ft_isdigit(mapster[i]) == 1 || mapster[i] == '-')
			{
				e->pts[y][x].z = ft_atoi(&mapster[i]) * e->height;
				e->pts[y][x].x = (x * e->z) - (y * e->z) + e->xpos;
				e->pts[y][x].y = (x * e->z + y * e->z) / 2 - e->pts[y][x].z \
				+ e->ypos;
				x++;
				while (mapster[i] != ' ')
					i++;
			}
			else
				i++;
		}
		y++;
	}
}

int			get_xmax(char *line, int x_max)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 1)
		{
			x++;
			while (ft_isdigit(line[i]) == 1 && line[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if ((x_max) % x != 0)
		ft_error(1);
	return (x);
}

void		ft_parsemap(int fd, t_env *e)
{
	char	*mapster;
	char	*line;
	char	*tmp;

	tmp = NULL;
	mapster = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		e->x_max = get_xmax(line, e->x_max);
		tmp = mapster;
		mapster = ft_strjoin(tmp, line);
		free(tmp);
		tmp = mapster;
		mapster = ft_strjoin(tmp, " ");
		free(tmp);
		free(line);
		e->y_max++;
	}
	if (close(fd) == -1)
		ft_error(1);
	if (!(e->pts = (t_pts **)malloc(sizeof(t_pts *) * e->y_max)))
		return ;
	ft_putintab(mapster, e, 0, 0);
}
