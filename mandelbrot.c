/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:04:30 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:17:01 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(t_fractol *fractal)
{
	double	z_real;
	double	z_imag;
	double	z_real_squared;
	double	z_imag_squared;
	int		i;

	z_real = 0.0;
	z_imag = 0.0;
	i = 0;
	fractal->cx = fractal->zx;
	fractal->cy = fractal->zy;
	while (i < fractal->iter)
	{
		z_real_squared = z_real * z_real;
		z_imag_squared = z_imag * z_imag;
		if (z_real_squared + z_imag_squared > DBL_MAX)
			return (i);
		z_imag = 2 * z_real * z_imag + fractal->cy;
		z_real = z_real_squared - z_imag_squared + fractal->cx;
		i++;
	}
	return (0);
}

int	is_it_mandel(int ac, char **ag)
{
	if (ac == 2)
	{
		if (ft_strncmp(ft_lowerall(ag[1]), "mandelbrot", 11) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
