/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:42:40 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:13:45 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_lowerall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

double	power(double base, int exponent)
{
	double	result;
	int		i;

	result = 1.0;
	i = 0;
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}

int	is_error(int ac, char **ag, t_fractol *f)
{
	if (is_it_mandel(ac, ag) == 1)
	{
		f->zx = 0.0;
		f->zy = 0.0;
		f->zoom = 0.005;
		f->name = 'm';
		return (1);
	}
	if (is_it_julia(ac, ag) == 1 && ac == 4)
	{
		f->zoom = 0.005;
		f->name = 'j';
		f->cx = string_to_double(ag[2]);
		f->cy = string_to_double(ag[3]);
		return (1);
	}
	if (is_it_julia(ac, ag) == 1 && ac == 2)
	{
		f->zoom = 0.005;
		f->name = 'j';
		f->cx = -0.7;
		f->cy = 0.23;
		return (1);
	}
	return (0);
}

void	init_fractal(t_fractol *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFFFFFF;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->iter = 40;
	fractal->width = 1520;
	fractal->height = 1080;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(1);
	fractal->win = mlx_new_window(fractal->mlx, fractal->width, fractal->height,
			"Fractal");
	if (!fractal->win)
		exit(1);
	fractal->image = mlx_new_image(fractal->mlx, fractal->width,
			fractal->height);
	if (!fractal->image)
		exit(1);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	fractal->cleanup = clean_exit;
	fractal->color_palette = NULL;
}
