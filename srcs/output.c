/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:14:47 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/21 13:20:38 by jquivogn         ###   ########.fr       */
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
	write(1, "-- Burningship --\n-- Bimandelbrot --\n", 37);
	write(1, "-- Negmandelbrot --\n-- Newton --\n", 33);
	write(1, "-- Collatz --\n", 14);
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
	"ON / OFF MOUSE JULIA : SPACE");
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

void	ft_name(t_env *ptr)
{
	ptr->f = ptr->fract == 0 ? "Julia" : ptr->f;
	ptr->f = ptr->fract == 1 ? "Mandelbrot" : ptr->f;
	ptr->f = ptr->fract == 2 ? "Burningship" : ptr->f;
	ptr->f = ptr->fract == 3 ? "Bimandelbrot" : ptr->f;
	ptr->f = ptr->fract == 4 ? "Negmandelbrot" : ptr->f;
	ptr->f = ptr->fract == 5 ? "Newton" : ptr->f;
	ptr->f = ptr->fract == 6 ? "Collatz" : ptr->f;
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 5, 1, 0xffffff,
	ptr->f);
}
