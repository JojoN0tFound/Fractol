/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:17:11 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/14 19:27:22 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_good_arg(char **av)
{
	if (!av[1])
		ft_usage();
	else
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			return (1);
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			return (1);
		if (ft_strcmp(av[1], "Burningship") == 0)
			return (1);
	}
	return (0);
}
