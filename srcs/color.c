/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:03:19 by jquivogn          #+#    #+#             */
/*   Updated: 2019/01/21 14:55:19 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			random_color(t_env *ptr)
{
	char		*c;
	static int	nb = 0;
	static int	value;
	int			bit;

	bit = ptr->name.rd;
	if (nb == 0)
	{
		if (!(c = malloc(999)))
			return (0);
		nb = (int)c;
		free(c);
	}
	nb = (nb * 41277);
	value = ((nb % 136257) * 0xff0000) >> bit;
	return (value < 0x00000f || value > 0xffffff ? random_color(ptr) : value);
}

int			red(int i, size_t color)
{
	size_t	r;
	size_t	b;
	size_t	g;

	r = (color & 0xff);
	g = (color & 0xff00) >> 8;
	b = (color & 0xff000) >> 16;
	r = i * 7 + 25;
	b = i * 4;
	g = i * 6;
	return ((b << 16) + (g << 8) + r);
}

int			blue(int i, size_t color)
{
	size_t	r;
	size_t	b;
	size_t	g;

	r = (color & 0xff);
	g = (color & 0xff00) >> 8;
	b = (color & 0xff000) >> 16;
	r = i * 6;
	b = i * 7 + 25;
	g = i * 4;
	return ((b << 16) + (g << 8) + r);
}

int			green(int i, size_t color)
{
	size_t	r;
	size_t	b;
	size_t	g;

	r = (color & 0xff);
	g = (color & 0xff00) >> 8;
	b = (color & 0xff000) >> 16;
	r = i * 4;
	b = i * 6;
	g = i * 7 + 25;
	return ((b << 16) + (g << 8) + r);
}

int			color(t_env *ptr, int it)
{
	if (ptr->fract == 5 && it == ptr->name.itmax)
		it = 0;
	if (ptr->fract == 5 || ptr->fract == 6)
		it *= 10;
	if (ptr->name.color == 1)
		return (random_color(ptr));
	if (ptr->name.color == 2)
		return (red(it, 0));
	if (ptr->name.color == 3)
		return (blue(it, 0));
	if (ptr->name.color == 4)
		return (green(it, 0));
	return (1);
}
