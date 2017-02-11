/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:19:52 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/11 20:24:25 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_putintab(char *mapster, t_env dstruct)
{
	int		i;
	int		x;
	int		y;

	y = 0;
	i = 0;
	if (!(dstruct.map = (int **)malloc(sizeof(int *) * dstruct.y_max)))
		return ;
	while (mapster[i] && (y < dstruct.y_max))
	{
		if (!(dstruct.map[y] = (int *)malloc(sizeof(int) * dstruct.x_max)))
			return ;
		x = 0;
		while (x < dstruct.x_max)
		{
			if (ft_isdigit(mapster[i]) == 1 || mapster[i] == '-')
			{
				dstruct.map[y][x] = ft_atoi(&mapster[i]);
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

void		ft_parsemap(int fd, t_env dstruct)
{
	char	*mapster;
	char	*line;
	char	*tmp;

	tmp = NULL;
	mapster = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		dstruct.x_max = get_xmax(line, dstruct.x_max);
		tmp = mapster;
		mapster = ft_strjoin(tmp, line);
		free(tmp);
		tmp = mapster;
		mapster = ft_strjoin(tmp, " ");
		free(tmp);
		free(line);
		dstruct.y_max++;
	}
	// if (close)
	ft_putintab(mapster, dstruct);
}
