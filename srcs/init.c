/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 00:16:01 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/26 00:30:59 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_fract		*ft_init(t_fract *ptr, char *fract)
{
	ptr->fract = 0;
	if (!(ptr->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGH, fract)))
	{
		free(ptr->mlx_ptr);
		return (NULL);
	}
	if (!(ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGH)))
	{
		free(ptr->mlx_ptr);
		free(ptr->win_ptr);
		return (NULL);
	}
	if (!(ptr->buff = mlx_get_data_addr(ptr->img_ptr, &ptr->bpp, &ptr->pix,\
					&ptr->endian)))
	{
		free(ptr->mlx_ptr);
		free(ptr->win_ptr);
		free(ptr->img_ptr);
		return (NULL);
	}
	return (ptr);
}
