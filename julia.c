/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:18:28 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:14:00 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iterations(t_fractol *fractal)
{
	double	z_real;
	double	z_imag;
	double	z_real_squared;
	double	z_imag_squared;
	int		i;

	z_real = fractal->zx;
	z_imag = fractal->zy;
	i = 0;
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

int	is_it_julia(int ac, char **ag)
{
	if (ac == 2)
	{
		if (ft_strncmp(ft_lowerall(ag[1]), "julia", 6) == 0)
			return (1);
		else
			return (0);
	}
	else if (ac == 4)
	{
		if (ft_strncmp(ft_lowerall(ag[1]), "julia", 6) == 0
			&& is_valid_double(ag[2]) == 1 && is_valid_double(ag[3]) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}
