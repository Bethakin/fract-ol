/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:16 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:16:22 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/home/beinan/Desktop/fract-ol/Libft/libft.h"
# include "/home/beinan/Desktop/fract-ol/minilibx-linux/mlx.h"
# include <float.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_fractol
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	int		width;
	int		height;
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
	void	(*cleanup)(struct s_fractol *f);
}			t_fractol;

int			julia_iterations(t_fractol *fractal);
int			mandelbrot_iterations(t_fractol *fractal);
int			ft_tolower(int c);
int			is_error(int ac, char **ag, t_fractol *f);
void		clean_exit(t_fractol *f);
int			is_it_mandel(int ac, char **ag);
char		*ft_lowerall(char *str);
int			is_valid_double(const char *str);
int			is_it_julia(int ac, char **ag);
double		power(double base, int exponent);
double		string_to_double(const char *str);
void		init_fractal(t_fractol *fractal);
void		draw_fractal(t_fractol *fractal);

#endif
