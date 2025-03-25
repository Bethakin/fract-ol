/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:06:58 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:12:41 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_fractol *fractol, int x, int y, int color)
{
	char	*pixel;

	pixel = fractol->pointer_to_image + (y * fractol->size_line + x
			* (fractol->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	get_color(int iterations, int max_iterations)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == max_iterations)
		return (0x000000);
	t = (double)iterations / max_iterations;
	t = sqrt(t);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	draw_fractal(t_fractol *fractal)
{
	int	x;
	int	y;
	int	color;
	int	iterations;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			fractal->zx = (x - fractal->width / 2.0) * fractal->zoom;
			fractal->zy = (y - fractal->height / 2.0) * fractal->zoom;
			if (fractal->name == 'm')
				iterations = mandelbrot_iterations(fractal);
			else if (fractal->name == 'j')
				iterations = julia_iterations(fractal);
			color = get_color(iterations, fractal->iter);
			put_pixel_to_image(fractal, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image, 0, 0);
}
