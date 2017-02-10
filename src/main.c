/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:35:01 by spalmaro          #+#    #+#             */
/*   Updated: 2017/02/10 17:19:21 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error(int i)
{
	i == 0 ? ft_putendl_fd("Usage : ./fdf <filename>", 1) : 0;
	exit(1);
}

int		main(int argc, char *argv)
{
	if (argc != 2)
		ft_error(0);
	else
	{
		ft_parse(argv[1]);
	}
	return (0);
}
