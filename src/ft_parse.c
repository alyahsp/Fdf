/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:52 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/10 19:52:14 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**ft_putintab(char *mapster, int x_max, int y_max)
{
	int		**map;
	int		i;
	int		x;
	int		y;

	y = 0;
	i = 0;
	if (!(map = (int **)malloc(sizeof(int *) * y_max)))
		return (NULL);
	while (mapster[i] && (y < y_max))
	{
		if (!(map[y] = (int *)malloc(sizeof(int) * x_max)))
			return (NULL);
		x = 0;
		while (x < x_max)
		{
			if (ft_isdigit(mapster[i]) == 1 || mapster[i] == '-')
			{
				map[y][x] = ft_atoi(&mapster[i]);
				x++;
				while (mapster[i] != ' ')
					i++;
			}
			else
				i++;
		}
		y++;
	}
	// y = 0;
	// x = 0;
	// while (map[y] && y < y_max)
	// {
	// 	x = 0;
	// 	while (x < x_max)
	// 	{
	// 		printf("y = %d x = %d value = %d\n", y, x, map[y][x]);
	// 		x++;
	// 	}
	// 	y++;
	// }
	return (map);
}

int		get_xmax(char *line, int *x_max)
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
			while (ft_isdigit(line[i]) == 1)
				i++;
		}
		else
			i++;
	}
	if ((*x_max) % x != 0)
		ft_error(1);
	return (x);
}

void		ft_parsemap(int fd, int y_max, int x_max)
{
	char	*mapster;
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) > 0)
	{
		x_max = get_xmax(line, &x_max);
		tmp = mapster;
		mapster = ft_strjoin(tmp, line);
		// free(tmp);
		free(line);
		y_max++;
	}
	// if (close)
	ft_putintab(mapster, x_max, y_max);
}
