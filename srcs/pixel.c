/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:11:20 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/10 18:17:49 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double		ft_abs(double a)
{
	return (a >= 0 ? a : -a);
}

t_env		*put_pixel(t_env *ptr, int x, int y, int color)
{
	int	*img;

	img = (int *)ptr->buff;
	if (x < WIDTH && y < HEIGH && x > 0 && y > 0)
		img[x + WIDTH * y] = color;
	return (ptr);
}
