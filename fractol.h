/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:11:16 by beinan            #+#    #+#             */
/*   Updated: 2025/03/21 10:00:01 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/beinan/Desktop/fract-ol/minilibx-linux/mlx.h"
#include "/home/beinan/Desktop/fract-ol/Libft/libft.h"

typedef struct s_fractal
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
	double	offset_x;
	double	offset_y;
	//double	zoom;
	char	name;
	int		iter;
// }			t_fractal;

// typedef struct s_image
// {
	void	*mlx;
	void	*win;
	int		zoom;	
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_fractal;



int	ft_tolower(int c);
int is_error(int ac, char **ag, t_fractal *f) ;