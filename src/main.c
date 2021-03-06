/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:35:01 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/21 21:37:02 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(int i)
{
	i == 0 ? ft_putendl_fd("Usage : ./fdf <filename>", 1) : 0;
	i == 1 ? ft_putendl_fd("Error", 1) : 0;
	i == 2 ? ft_putendl_fd("Out of Window", 1) : 0;
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_env	e;

	if (argc != 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	e = (t_env) {NULL, NULL, NULL, NULL, 0, 0, 0, NULL, 0, 0, 10, 5, 400, 400,\
	0, 0, 0, 0, 0, 0, 0};
	ft_parsemap(fd, &e);
	ft_drawmap(e);
	return (0);
}
