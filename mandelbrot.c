/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   madelbrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:04:30 by beinan            #+#    #+#             */
/*   Updated: 2025/03/22 15:30:59 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <float.h>
#include "fractol.h"

// int mandelbrot_iterations(double real_c, double imag_c, int max_iterations)
// {
//     double z_real = 0.0;
//     double z_imag = 0.0;
//     double z_real_squared, z_imag_squared;

//     int i = 0;
//     while (i < max_iterations)
//     {
//         z_real_squared = z_real * z_real;
//         z_imag_squared = z_imag * z_imag;
//         if (z_real_squared + z_imag_squared > DBL_MAX)
//             return i;
//         z_imag = 2 * z_real * z_imag + imag_c;
//         z_real = z_real_squared - z_imag_squared + real_c;

//         i++;
//     }

//     return 0;
// }
#include <float.h> 

int mandelbrot_iterations(t_fractol *fractal)
{
    double z_real;
    double z_imag;
    double z_real_squared;
    double z_imag_squared;
    int i;

    z_real = 0.0;
    z_imag = 0.0;
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
// int main() {
//     double real_c, imag_c;

//     printf("Bir karmaşık sayının reel kısmını girin (real_c): ");
//     scanf("%lf", &real_c);
//     printf("Bir karmaşık sayının sanal kısmını girin (imag_c): ");
//     scanf("%lf", &imag_c);

//     int result = mandelbrot_iterations(real_c, imag_c, 60);
    
//     if (result == 0) {
//         printf("Verilen c noktası Mandelbrot setindedir (yakınsama).\n");
//     } else {
//         printf("Verilen c noktası %d. iterasyonda divergent oldu.\n", result);
//     }

//     return 0;
// }
