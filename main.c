/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:04:47 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:14:03 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(t_fractol *f)
{
	if (f->image)
		mlx_destroy_image(f->mlx, f->image);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

int	keyhook(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
	{
		fractol->cleanup(fractol);
		exit(0);
	}
	else if (keycode == 101)
		fractol->iter += 10;
	else if (keycode == 114)
		fractol->iter -= 10;
	draw_fractal(fractol);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom *= 0.9;
	else if (button == 5)
		fractol->zoom *= 1.1;
	draw_fractal(fractol);
	return (0);
}

int	closehook(t_fractol *f)
{
	f->cleanup(f);
	exit(0);
}

int	main(int ac, char **ag)
{
	t_fractol	fractol;

	if (is_error(ac, ag, &fractol) == 0)
	{
		write(2, "./fractol mandelbrot or ./fractol julia <r> <i>", 48);
		exit(1);
	}
	init_fractal(&fractol);
	draw_fractal(&fractol);
	mlx_hook(fractol.win, 17, 0, closehook, &fractol);
	mlx_hook(fractol.win, 2, 1, keyhook, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
