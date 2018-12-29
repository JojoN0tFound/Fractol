/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:14:47 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/26 00:30:47 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_error(char *fract)
{
	write (1, "Error: ", 7);
	ft_putendl(fract);
	return (0);
}

int		ft_usage(void)
{
	write(1, "usage : ./fractol <fractol's name>\n", 35);
	//write(1, "       or\n", 10);
	//write(1, "usage : ./fractol <fractol's name> <fractol's name>\n", 52);
	write(1, "\nfractol list :\n-- Julia --\n-- Mandelbrot --\n", 45);
	return (0);
}
