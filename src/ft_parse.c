/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:52 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/19 18:03:45 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_putintab(char *mapster, t_env *e, int i, int y)
{
	int		x;

	if (!(e->coord = (t_coord **)malloc(sizeof(t_coord *) * e->y_max)))
		return ;
	while (mapster[i] && (y < e->y_max))
	{
		if (!(e->coord[y] = (t_coord *)malloc(sizeof(t_coord) * e->x_max)))
			return ;
		x = 0;
		while (x < e->x_max)
		{
			if (ft_isdigit(mapster[i]) == 1 || mapster[i] == '-')
			{
				e->coord[y][x].z = ft_atoi(&mapster[i]);
				e->coord[y][x].x = x;
				e->coord[y][x].y = y;
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

int		get_xmax(char *line, int x_max)
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
	// if (close)
	ft_putintab(mapster, e, 0, 0);
}
