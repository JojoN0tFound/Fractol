/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:18:41 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/26 14:50:55 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			ft_julia(t_fract *ptr)
{
	(void)ptr;
	return (1);
}

/*définir x1 = -1
définir x2 = 1
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100
définir iteration_max = 150

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1 
    Pour y = 0 tant que y < image_y par pas de 1
        définir c_r = 0.285
        définir c_i = 0.01
        définir z_r = x / zoom + x1
        définir z_i = y / zoom + y1
        définir i = 0

        Faire
            définir tmp = z_r
            z_r = z_r*z_r - z_i*z_i + c_r
            z_i = 2*z_i*tmp + c_i
            i = i+1
        Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

        si i = iteration_max
            dessiner le pixel de coordonné (x; y)
        finSi
    finPour
finPour*/