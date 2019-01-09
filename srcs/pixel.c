/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:11:20 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/09 20:39:47 by jquivogn         ###   ########.fr       */
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
	static int	n = 0;

	if (n == 0)
	{
		if (!(c = malloc(1)))
			return (0);
		n = (int)c;
		free(c);
	}
	if (nb == 0)
	{
		if (!(c = malloc(999)))
			return (0);
		nb = (int)c;
		free(c);
	}
	nb = (nb * 4127);
	return ((nb % 13625) * 255 * 255);
}

t_env		*put_pixel(t_env *ptr, int x, int y, int color)
{
	int	*img;

	img = (int *)ptr->buff;
	if (x < WIDTH && y < HEIGH)
		img[x + WIDTH * y] = color;
	return (ptr);
}
