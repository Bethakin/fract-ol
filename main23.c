/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main23.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:38:48 by beinan            #+#    #+#             */
/*   Updated: 2025/03/22 17:33:36 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/home/beinan/Desktop/fract-ol/minilibx-linux/mlx.h"


// int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
// {
//  fractal->x = 0;
//  fractal->y = 0;
//  while (fractal->x < 1920)
//  {
//   while (fractal->y < 1080)
//   {
//    if (ft_strncmp(query, "mandel", 7) == 0)
//     calculate_mandelbrot(fractal);
//    else if (ft_strncmp(query, "julia", 6) == 0)
//     calculate_julia(fractal, cx, cy);
//    else if (ft_strncmp(query, "ship", 5) == 0)
//     calculate_burning_ship(fractal);
//    else
//    {
//     ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
//     exit_fractal(fractal);
//    }
//    fractal->y++;
//   }
//   fractal->x++;
//   fractal->y = 0;
//  }
//  mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
//   0);
//  return (0);
// }
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// 	int		color;
// }				t_vars;

// int     change_color(t_vars *data)
// {
//     // Fill the window with the current color
// //  mlx_clear_window(data->mlx, data->win);
//     mlx_string_put(data->mlx, data->win, 150, 150, data->color, "Color Changing Window!");

//     // Cycle through some basic colors: RED, GREEN, BLUE
//     if (data->color == 0xFF0000)        // If it's red
//         data->color = 0x00FF00;        // Change to green
//     else if (data->color == 0x00FF00)   // If it's green
//         data->color = 0x0000FF;        // Change to blue
//     else
//         data->color = 0xFF0000;        // Otherwise, go back to red

//     return (0);
// }


// int	mouse_hook(int keycode)
// {
//     // if(keycode == 65307)
//     // {
//     //     mlx_destroy_window(vars->mlx, vars->win);
// 	// 	exit(0);
//     // }
// 	printf("%d\n", keycode);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1520, 1080, "Hello world!");
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	mlx_key_hook(vars.win, key_hook, &vars);
//     mlx_loop_hook(vars.mlx,
//         change_color,
// 	    &vars);
// 	mlx_loop(vars.mlx);
// }
// int	main(void)
// {13
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1520, 1080, "Fract-ol");
// 	mlx_loop(mlx);
// }

/// 1 2 3
// yukarı 4 aşa 5


// #include "minilibx-linux/mlx.h"
// #include <X11/keysym.h>
// #include <stdlib.h>

// #define MALLOC_ERROR	1
// #define	SIDE_LEN		800

// typedef	unsigned char	byte;

// /*
//  * bitwise operation to get the color value..
//  *
//  * TLDR
//  * i prefer #defines ...or better, writing directly in hexadecimal
// */
// int	encode_rgb(byte red, byte green, byte blue)
// {
//     return (red << 16 | green << 8 | blue);
// }


// typedef struct	s_var
// {
// 	void	*mlx;
// 	void	*win;
// 	int		offset_x;
// 	int		offset_y;
// 	int		zoom;
// }				t_var;


// void	color_screen(t_var *data, int color)
// {
// 	for (int y = 0; y < SIDE_LEN - 400; ++y)	
// 	{
// 		for (int x = 0; x < SIDE_LEN; ++x)
// 		{
// 			/*
// 			 * This function really suck 👎🏻
// 			 * 	~No buffer, i can literally see the pixels being drawn
// 			*/
// 			mlx_pixel_put(data->mlx,
// 						data->win, 
// 						x, 
// 						y, 
// 						color);
// 		}
// 	}
// }
// void	zoom(t_var *fractal, int x, int y, int zoom)
// {
// 	double	zoom_level;

// 	zoom_level = 1.42;
// 	if (zoom == 1)
// 	{
// 		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
// 				/ (fractal->zoom * zoom_level));
// 		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
// 				/ (fractal->zoom * zoom_level));
// 		fractal->zoom *= zoom_level;
// 	}
// 	else if (zoom == -1)
// 	{
// 		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
// 				/ (fractal->zoom / zoom_level));
// 		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
// 				/ (fractal->zoom / zoom_level));
// 		fractal->zoom /= zoom_level;
// 	}
// 	else
// 		return ;
// }
// int	mouse_hook(int mouse_code, int x, int y, t_var *fractal)
// {
// 	if (mouse_code == 4)
// 		zoom(fractal, x, y, 1);
// 	else if (mouse_code == 5)
// 		zoom(fractal, x, y, -1);
// 	return (0);
// }
// /*
//  * KeySym values in X11/keysym.h
//  * ~https://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
// */
// int	f(int keysym, t_var *data)
// {
// 	if (keysym == XK_r)
// 	{
// 		color_screen(data, encode_rgb(255, 0, 0));	
// 	}
// 	else if (keysym == XK_g)
// 	{
// 		color_screen(data, encode_rgb(0, 0xff, 0));	
// 	}
// 	else if (keysym == XK_b)
// 	{
// 		color_screen(data, encode_rgb(0, 0, 0xff));	
// 	}	

// 	if(keysym == 65307)
//     {
//         mlx_destroy_window(data->mlx, data->win);
// 		exit(0);
//     }
// 	return 0;
// }

// /*
//  * All the checks for errors like 
//  * 		
//  * 	~if (vars.mlx == NULL) exit(1);
//  *
//  * are not written to not clog te code!
//  * But u know this stuff is a necessary evil 😂
// */
// int	main()
// {
// 	t_var	data;

// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx,
// 								SIDE_LEN,
// 								SIDE_LEN,
// 								"My window");

// 	mlx_key_hook(data.win, f, &data);
// 	mlx_mouse_hook(data.win, mouse_hook, &data);

// 	mlx_loop(data.mlx);
// }

#include "fractol.h"

// int stop_f(t_fractal *f)
// {
// 	mlx_destroy_image(f->mlx, f->image);
// 	mlx_destroy_window(f->mlx, f->win);
// 	free(f->mlx);
// 	free(f);
// 	f->cx = 0;
// 	exit(0);
// 	return (0);
// }
// int stop_f(int keycode, t_fractal *fractal)
// {
//     if (keycode == 17) {  // Close window
//         mlx_destroy_window(fractal->mlx, fractal->win);
//         free(fractal);  // Free memory safely if needed
//         exit(0);  // Exit the program cleanly
//     }
//     return (0);
// }

// int	key_hook(int keycode, t_fractal *vars)
// {
//     if(keycode == 65307)
//     {
//         mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
//     }
// 	return (0);
// }

int keyhook(int key, t_fractol *a)
{
	a->x=0;
	if(key == 65307)
		exit(0);
	return(0);
}
// int closehook(int key, t_fractal *a)
// {
// 	key = 0;
// 	a->x=0;
// 	exit(1);
// 	return(key);
// }
int closehook(int keycode, t_image f)
{
    //mlx_destroy_window(f.mlx, f.win);  // Pencereyi yok et
    //free(fractal);  // Belleği serbest bırak
    exit(0);  // Programı düzgün şekilde sonlandır
    return (keycode);
}

#include <stdio.h>

int main(int ac, char **ag)
{
	t_fractol fractal;

	if (is_error(ac, ag, &fractal) == 0)
	{
		return (0);
	}
	im.mlx = mlx_init();
	im.win = mlx_new_window(im.mlx, 1520, 1080, "Fractol");
	mlx_hook(im.win, 17, 0, closehook, &im);
	mlx_hook(im.win, 2, 1, keyhook, &fractal);

	//mlx mouse hook

	mlx_loop(im.mlx);

}
