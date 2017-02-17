/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:35:01 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/16 15:31:34 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(int i)
{
	i == 0 ? ft_putendl_fd("Usage : ./fdf <filename>", 1) : 0;
	i == 1 ? ft_putendl_fd("Error", 1) : 0;
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_env	list;

	if (argc != 2)
		ft_error(0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(1);
	list = (t_env) {0, 0, NULL};
	ft_parsemap(fd, list);
	ft_drawmap(list);
	return (0);
}
