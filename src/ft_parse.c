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

int		get_xmax(char *line)
{
	
}

void		ft_parse(int fd)
{
	int		x_max;
	int		y_max;
	char	*line;

	y = -1;
	x = -1;
	while (get_next_line(fd, &line) > 0)
	{

		y_max++;
	}
}
