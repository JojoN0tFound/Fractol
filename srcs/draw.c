/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:17:50 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/26 00:49:25 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h" 

void	put_pixel(t_fract *ptr, int x, int y, int color)
{
	int	*img;

	img = (int *)ptr->buff;
	if (x < WIDTH && y < HEIGH)
		img[x + WIDTH * y] = color;
}

int			ft_fractol(t_fract *ptr)
{
	int	(*draw[2])(t_fract *);

	draw[0] = &ft_julia;
	draw[1] = &ft_mandelbrot;
	if (!draw[ptr->fract - 1](ptr))
	//	return (0);
	//mlx_hook(ptr->win_ptr, 2, 1L << 0, key_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
	mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
	mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	free(ptr->mlx_ptr);
	return (1);
}
