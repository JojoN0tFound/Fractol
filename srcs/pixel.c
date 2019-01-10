/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:11:20 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/10 14:10:54 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double		ft_abs(double a)
{
	return (a >= 0 ? a : -a);
}

int			random_color(void)
{
	char		*c;
	static int	nb = 0;
	static int	value;

	if (nb == 0)
	{
		if (!(c = malloc(999)))
			return (0);
		nb = (int)c;
		free(c);
	}
	nb = (nb * 4127);
	value = (nb % 13625) * 255 * 255;
	return (value < 1000 ? 3000 : value);
}

t_env		*put_pixel(t_env *ptr, int x, int y, int color)
{
	int	*img;

	img = (int *)ptr->buff;
	x += ptr->x1;
	y += ptr->y1;
	if (x < WIDTH && y < HEIGH && x > 0 && y > 0)
		img[x + WIDTH * y] = color;
	return (ptr);
}
