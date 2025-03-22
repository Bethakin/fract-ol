/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:04:47 by beinan            #+#    #+#             */
/*   Updated: 2025/03/22 18:52:41 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h> // For exit()
#include <stdio.h>  // For fprintf()

void init_fractal(t_fractol *fractal)
{
    fractal->x = 0;
    fractal->y = 0;

    fractal->cx = -0.7; // Example value for Julia
    fractal->cy = 0.23; // Example value for Julia
    fractal->color = 0xFFFFFF; // Default color (white)
    fractal->offset_x = 0.0;
    fractal->offset_y = 0.0;
    fractal->iter = 50;
    fractal->zoom = 0.005;
    fractal->width = 1520; // Example window width
    fractal->height = 1080; // Example window height
    // Initialize MiniLibX
    fractal->mlx = mlx_init();
    if (!fractal->mlx)
    {
        fprintf(stderr, "Error: mlx_init failed\n");
        exit(1);
    }

    // Create a new window
    fractal->win = mlx_new_window(fractal->mlx, fractal->width, fractal->height, "Fractal");
    if (!fractal->win)
    {
        fprintf(stderr, "Error: mlx_new_window failed\n");
        exit(1);
    }

    // Create a new image
    fractal->image = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
    if (!fractal->image)
    {
        fprintf(stderr, "Error: mlx_new_image failed\n");
        exit(1);
    }

    // Get the image's memory address
    fractal->pointer_to_image = mlx_get_data_addr(
        fractal->image,
        &fractal->bits_per_pixel,
        &fractal->size_line,
        &fractal->endian
    );

    // Initialize fractal-specific data

    // Optional: Initialize color palette
    fractal->color_palette = NULL; // You can initialize this later if needed
}
void init_image(t_fractol *fractol)
{
    // Initialize MiniLibX
    fractol->mlx = mlx_init();
    fractol->win = mlx_new_window(fractol->mlx, fractol->width, fractol->height, "Fractal");

    // Create a new image
    fractol->image = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
    fractol->pointer_to_image = mlx_get_data_addr(
        fractol->image,
        &fractol->bits_per_pixel,
        &fractol->size_line,
        &fractol->endian
    );

    // Set image dimensions
    fractol->width = fractol->width;
    fractol->height = fractol->height;
}

void put_pixel_to_image(t_fractol *fractol, int x, int y, int color)
{
    char *pixel;

    // Calculate the pixel's memory address
    pixel = fractol->pointer_to_image + (y * fractol->size_line + x * (fractol->bits_per_pixel / 8));

    // Write the color to the pixel
    *(int *)pixel = color;
}
// int get_color(int iterations, int max_iterations)
// {
//     if (iterations == max_iterations)
//         return 0x000000; // Black for points inside the set

//     // Define a color palette
//     int palette[] = {
//         0x0000FF, // White
//         0x00FF00, // Green
//         0x0000FF, // Blue
//         0xFFFF00, // Yellow
//         0xFF00FF, // Magenta
//         0x00FFFF  // Cyan
//     };
//     int palette_size = sizeof(palette) / sizeof(palette[0]);

//     // Map iterations to a color in the palette
//     int index = (int)((double)iterations / max_iterations * palette_size);
//     return palette[index % palette_size];
// }

// #include <math.h>

// int get_color(int iterations, int max_iterations)
// {
//     if (iterations == max_iterations)
//         return 0x000000; // Black for points inside the set

//     // Smooth color mapping using a logarithmic function
//     double t = (double)iterations / max_iterations;
//     t = log(t + 1) / log(2); // Apply logarithmic scaling

//     // Map to RGB using trigonometric functions for smooth transitions
//     int r = (int)(255 * (0.5 + 0.5 * sin(2 * M_PI * t)));
//     int g = (int)(255 * (0.5 + 0.5 * sin(2 * M_PI * t + 2 * M_PI / 3)));
//     int b = (int)(255 * (0.5 + 0.5 * sin(2 * M_PI * t + 4 * M_PI / 3)));

//     return (r << 16) | (g << 8) | b; // Combine into RGB color
// }
// int get_color(int iterations, int max_iterations)
// {
//     if (iterations == max_iterations)
//         return 0x000000; // Black for points inside the set

//     // Define a color palette
//     int palette[] = {
//         0xFF0000, // Red
//         0x00FF00, // Green
//         0x0000FF, // Blue
//         0xFFFF00, // Yellow
//         0xFF00FF, // Magenta
//         0x00FFFF  // Cyan
//     };
//     int palette_size = sizeof(palette) / sizeof(palette[0]);

//     // Smooth color mapping using a logarithmic function
//     double t = (double)iterations / max_iterations;
//     t = log(t + 1) / log(2); // Apply logarithmic scaling

//     // Map to the palette
//     int index = (int)(t * palette_size);
//     return palette[index % palette_size];
// }

int get_color(int iterations, int max_iterations)
{
    if (iterations == max_iterations)
        return 0x000000;

    int r = (int)(255 * ((double)iterations / max_iterations));
    int g = (int)(255 * (0.6 - (double)iterations / max_iterations));
    int b = (int)(255 * (0.8 - (double)iterations / max_iterations));

    return (r << 16) | (g << 8) | b; // Combine into RGB color
}

// void draw_fractal(t_fractol *fractal)
// {
//     int x, y;
//     int color;
//     int iterations;

//     for (y = 0; y < fractal->height; y++)
//     {
//         for (x = 0; x < fractal->width; x++)
//         {
//             // Map pixel coordinates to the complex plane
//             // double real = (x - fractal->width / 2.0) * fractal->zoom + fractal->offset_x;
//             // double imag = (y - fractal->height / 2.0) * fractal->zoom + fractal->offset_y;

//             // Compute the number of iterations
//             if (fractal->name == 'm') // Mandelbrot
//                 iterations = mandelbrot_iterations(fractal);
//             else if (fractal->name == 'j') // Julia
//                 iterations = julia_iterations(fractal);

//             color = get_color(iterations, fractal->iter);
//             put_pixel_to_image(fractal, x, y, color);
//         }
//     }
//     mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image, 0, 0);
// }
void draw_fractal(t_fractol *fractal)
{
    int x, y;
    int color;
    int iterations;

    for (y = 0; y < fractal->height; y++)
    {
        for (x = 0; x < fractal->width; x++)
        {
            // Map pixel coordinates to the complex plane
            double real = (x - fractal->width / 2.0) * fractal->zoom + fractal->offset_x;
            double imag = (y - fractal->height / 2.0) * fractal->zoom + fractal->offset_y;

            if (fractal->name == 'm') // Mandelbrot
            {    
                // fractal->zx = 0.0;
                // fractal->zy = 0.0;

                fractal->cx = real; // Set c to the pixel coordinates
                fractal->cy = imag;
                iterations = mandelbrot_iterations(fractal);
            }
            else if (fractal->name == 'j') // Julia
            {
                fractal->cx = real; // Set z to the pixel coordinates
                fractal->cy = imag;
                iterations = julia_iterations(fractal);
            }

            // Map iterations to a color
            color = get_color(iterations, fractal->iter);

            // Draw the pixel to the image buffer
            put_pixel_to_image(fractal, x, y, color);
        }
    }

    // Display the image in the window
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image, 0, 0);
}

int key_hook(int keycode, t_fractol *fractol)
{
    if (keycode == 53) // ESC key
        exit(0);
    else if (keycode == 24) // '+' key to increase iterations
        fractol->iter += 10;
    else if (keycode == 27) // '-' key to decrease iterations
        fractol->iter -= 10;

    // Redraw the fractal
    draw_fractal(fractol); // Assuming `img` is accessible here
    return 0;
}

int mouse_hook(int button, int x, int y, t_fractol *fractol)
{
    (void) x;
    (void) y;
    if (button == 4) // Scroll up (zoom in)
        fractol->zoom *= 0.9;
    else if (button == 5) // Scroll down (zoom out)
        fractol->zoom *= 1.1;

    // Redraw the fractal
    draw_fractal(fractol); // Assuming `img` is accessible here
    return 0;
}
// int key_hook(int keycode, t_fractol *fractol)
// {
//     if (keycode == 53) // ESC key
//         exit(0);
//     else if (keycode == 24) // '+' key to increase iterations
//         fractol->iter += 10;
//     else if (keycode == 27) // '-' key to decrease iterations
//         fractol->iter -= 10;

//     // Redraw the fractal
//     draw_fractal(fractol);
//     return 0;
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
int closehook(int keycode)
{
    //mlx_destroy_window(f.mlx, f.win);  // Pencereyi yok et
    //free(fractal);  // Belleği serbest bırak
    exit(0);  // Programı düzgün şekilde sonlandır
    return (keycode);
}

int main(int ac, char **ag)
{
    t_fractol fractol;


	if (is_error(ac, ag, &fractol) == 0)
	{
		return (0);
	}
    // Initialize fractal parameters
    // fractol.width = 800;
    // fractol.height = 600;
    // fractol.zoom = 0.005;
    // fractol.offset_x = -0.5;
    // fractol.offset_y = 0.0;
    // fractol.iter = 50;
    // fractol.cx = -0.7; // Example value for Julia
    // fractol.cy = 0.23; // Example value for Julia

    // Initialize MiniLibX and create the image
    init_fractal(&fractol);

    // Draw the fractal
    draw_fractal(&fractol);

    // Set up event hooks
	mlx_hook(fractol.win, 17, 0, closehook, &fractol);
	mlx_hook(fractol.win, 2, 1, keyhook, &fractol);

    mlx_mouse_hook(fractol.win, mouse_hook, &fractol);

    // Start the event loop
    mlx_loop(fractol.mlx);

    return 0;
}