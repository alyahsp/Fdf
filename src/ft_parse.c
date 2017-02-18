/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:52 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/18 19:49:33 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_putintab(char *mapster, t_env list, int i, int y)
{
	int		x;

	if (!(list.coord = (t_coord **)malloc(sizeof(t_coord *) * list.y_max)))
		return ;
	while (mapster[i] && (y < list.y_max))
	{
		if (!(list.coord[y] = (t_coord *)malloc(sizeof(t_coord) * list.x_max)))
			return ;
		x = 0;
		while (x < list.x_max)
		{
			if (ft_isdigit(mapster[i]) == 1 || mapster[i] == '-')
			{
				list.coord[y][x].z = ft_atoi(&mapster[i]);
				list.coord[y][x].x = x;
				list.coord[y][x].y = y;
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

void		ft_parsemap(int fd, t_env list)
{
	char	*mapster;
	char	*line;
	char	*tmp;

	tmp = NULL;
	mapster = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		list.x_max = get_xmax(line, list.x_max);
		tmp = mapster;
		mapster = ft_strjoin(tmp, line);
		free(tmp);
		tmp = mapster;
		mapster = ft_strjoin(tmp, " ");
		free(tmp);
		free(line);
		list.y_max++;
	}
	// if (close)
	ft_putintab(mapster, list, 0, 0);
}
