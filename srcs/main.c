/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julesqvgn <julesqvgn@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:03:12 by julesqvgn         #+#    #+#             */
/*   Updated: 2018/12/26 00:30:53 by julesqvgn        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_princ(char *fract)
{
	t_fract	*ptr;

	if (!(ptr = (t_fract *)malloc(sizeof(t_fract))))
		return (0);
	if (!(ptr = ft_init(ptr, fract)))
	{
		free(ptr);
		ft_error(fract);
		return (0);
	}
	ptr->fract = ft_strcmp(fract, "Julia") == 0 ? 1 : 0;
	ptr->fract = ft_strcmp(fract, "Mandelbrot") == 0 ? 2 : 0;
	if (!ft_fractol(ptr))
		ft_error(fract);
	free(ptr);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1 || ac > 3)
		ft_usage();
	else if (!av[2] && ft_good_arg(av))
	{
		ft_princ(av[1]);
	}
	// else if (ft_good_arg(av) && ft_good_arg(av + 1) && ft_strcmp(av[1], av[2]))
	// {
	// 	ft_princ(av[1]);
	// 	ft_princ(av[2]);
	// }
	else
	{
		ft_usage();
	}
	return (0);
}