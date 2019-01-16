/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:03:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2019/01/16 15:44:28 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_princ(char *fract)
{
	t_env	*ptr;

	if (!(ptr = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (!(ptr = ft_init(ptr, fract)))
	{
		free(ptr);
		ft_error(fract);
		return (0);
	}
	ptr->jmouse = 0;
	ptr->f = fract;
	ptr->fract = (ft_strcmp(fract, "Julia") == 0) ? 0 : ptr->fract;
	ptr->fract = (ft_strcmp(fract, "Mandelbrot") == 0) ? 1 : ptr->fract;
	ptr->fract = (ft_strcmp(fract, "Burningship") == 0) ? 2 : ptr->fract;
	ptr->fract = (ft_strcmp(fract, "Bimandelbrot") == 0) ? 3 : ptr->fract;
	ptr->fract = (ft_strcmp(fract, "Negmandelbrot") == 0) ? 4 : ptr->fract;
	if (ptr->fract == -1 || !ft_fractol(ptr))
		ft_error(fract);
	free(ptr);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1 || ac > 3)
		ft_usage();
	else if (!av[2] && ft_good_arg(av))
		ft_princ(av[1]);
	else
	{
		ft_usage();
	}
	return (0);
}
