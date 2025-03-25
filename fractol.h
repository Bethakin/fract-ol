/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:16 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 14:31:32 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/beinan/Desktop/fract-ol/minilibx-linux/mlx.h"
#include "/home/beinan/Desktop/fract-ol/Libft/libft.h"
#include <float.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_fractol
{
	//void	*mlx;
	//void	*window;
	
	// void	*pointer_to_image;
	// int		bits_per_pixel;
	// int		size_line;
	// int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	int 	width;
	int 	height;
	double	offset_x;
	double	offset_y;
	int		iter;
	double	zoom;
	char	name;
	void	*mlx;
	void	*win;
	void	*image;
	int		*color_palette;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	void	 (*cleanup)(struct s_fractol *f);
}			t_fractol;

int julia_iterations(t_fractol *fractal);
int mandelbrot_iterations(t_fractol *fractal);
int	ft_tolower(int c);
int is_error(int ac, char **ag, t_fractol *f) ;