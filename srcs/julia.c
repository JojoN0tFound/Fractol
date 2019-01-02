/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:18:41 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/30 00:05:40 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_fract     *julia_init(t_fract *ptr)
{
    t_julia julia;

    julia.x = 0;
    julia.x1 = -1;
    julia.x2 = 1;
    julia.img_x = julia.x2 - julia.x1;
    julia.y = 0;
    julia.y1 = -1.2;
    julia.y2 = 1.2;
    julia.img_y = julia.y2 - julia.y1;
    julia.zoom = 100;
    julia.itmax = 150;
    julia.c_r = 0.285;
    julia.c_i = 0.01;
    julia.z_r = julia.x / julia.zoom + julia.x1;
    julia.z_i = julia.y / julia.zoom + julia.y1;
    julia.color = 0;
    ptr->name = (void *)julia;
    return (ptr);
}

int         ft_draw_julia(t_fract *ptr)
{
    int     i;
    double  tmp;

    i = 0;
    while(ptr->julia.x < ptr->julia.img_x)
    {
        while(ptr->julia.y < ptr->julia.img_y)
        {
            tmp = ptr->julia.z_r;
            ptr->julia.z_r = ptr->julia.z_r * ptr->julia.z_r - ptr->julia.z_i * ptr->julia.z_i + ptr->julia.c_r;
            ptr->julia.z_i = 2 * ptr->julia.z_i * tmp + ptr->julia.c_i
            i++;

        }
    }
    return(1);
}

int			ft_julia(t_fract *ptr)
{
    ptr = julia_init(ptr);
    if (!ft_draw_julia)
        return (0);
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