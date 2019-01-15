/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:14:47 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/15 14:16:10 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_error(char *fract)
{
	write(1, "Error: ", 7);
	ft_putendl(fract);
	return (0);
}

int		ft_usage(void)
{
	write(1, "usage : ./fractol <fractol's name>\n", 35);\
	write(1, "\nfractol list :\n-- Julia --\n-- Mandelbrot --\n", 45);
	write(1, "-- Burningship --\n", 18);
	return (0);
}

int		ft_command(t_env *ptr)
{
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 1, 0xffffff,
	"MOVE :         UP    -> W  DOWN -> S");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 600, 20, 0xffffff,
	"RIGTH -> D  LEFT -> A");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 45, 0xffffff,
	"COLOR :        RANDOM RGB  -> 1 (multipress)");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 600, 65, 0xffffff,
	"BLUE THEME  -> 2");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 600, 85, 0xffffff,
	"RED THEME   -> 3");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 600, 105, 0xffffff,
	"GREEN THEME -> 4");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 130, 0xffffff,
	"CHANGE FRACTAL : C   RESET : R");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 155, 0xffffff,
	"ON / OFF MOUSE JULIA : SAPCE");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 180, 0xffffff,
	"ZOOM : MOUSE UP      DEZOOM : MOUSE DOWN");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 205, 0xffffff,
	"UP ITMAX : +         DOWN ITMAX : -");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 230, 0xffffff,
	"SHOW / HIDE TOOGLE BAR : T");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 450, 255, 0xffffff,
	"EXIT : ESCAPE");
	return (0);
}
