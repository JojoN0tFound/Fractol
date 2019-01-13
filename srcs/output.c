/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:14:47 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/12 16:48:27 by julesqvgn        ###   ########.fr       */
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

int		ft_command(void)
{
	write(1, "/**************************************************\\\n", 53);
	write(1, "*                      COMMAND                     *\n", 53);
	write(1, "*                                                  *\n", 53);
	write(1, "*  MOVE :         UP    -> Z  DOWN -> S            *\n", 53);
	write(1, "*                 RIGTH -> D  LEFT -> Q            *\n", 53);
	write(1, "*                                                  *\n", 53);
	write(1, "*  COLOR :        RANDOM RGB  -> 1 (multipress)    *\n", 53);
	write(1, "*                 RED THEME   -> 2                 *\n", 53);
	write(1, "*                 BLUE THEME  -> 3                 *\n", 53);
	write(1, "*                 GREEN THEME -> 4                 *\n", 53);
	write(1, "*                                                  *\n", 53);
	write(1, "*  CHANGE FRACTAL : C   RESET : R                  *\n", 53);
	write(1, "*                                                  *\n", 53);
	write(1, "*  AUTO ZOOM : A        AUTO DEZOOM : E            *\n", 53);
	write(1, "*                                                  *\n", 53);
	write(1, "*  ZOOM : MOUSE UP      DEZOOM : MOUSE DOWN        *\n", 53);
	write(1, "*                                                  *\n", 53);
	write(1, "\\**************************************************/\n", 53);
	return (0);
}