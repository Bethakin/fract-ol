/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:18:28 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 13:01:54 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

// int julia_iterations(double real_z, double imag_z, double real_c, double imag_c, int max_iterations)
// {
//     double z_real = real_z;
//     double z_imag = imag_z;
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

// int julia_iterations(t_fractol *fractal)
// {
//     double z_real;
//     double z_imag;
//     double z_real_squared;
//     double z_imag_squared;
//     int i;

//     z_real = fractal->zx;
//     z_imag = fractal->zy;
//     i = 0;
//     while (i < fractal->iter)
//     {
//         z_real_squared = z_real * z_real;
//         z_imag_squared = z_imag * z_imag;
//         if (z_real_squared + z_imag_squared > DBL_MAX)
//             return i;
//         z_imag = 2 * z_real * z_imag + fractal->cy;
//         z_real = z_real_squared - z_imag_squared + fractal->cx;
//         i++;
//     }
//     return 0;
// }
int julia_iterations(t_fractol *fractal)
{
    double z_real = fractal->zx; // Starting point for Julia (pixel coordinate)
    double z_imag = fractal->zy;
    double z_real_squared;
    double z_imag_squared;

    int i = 0;
    while (i < fractal->iter)
    {
        z_real_squared = z_real * z_real;
        z_imag_squared = z_imag * z_imag;

        // Escape condition: if |z| > 2
        if (z_real_squared + z_imag_squared > DBL_MAX)
            return i;

        // Update z = z² + c
        z_imag = 2 * z_real * z_imag + fractal->cy; // cy is the constant
        z_real = z_real_squared - z_imag_squared + fractal->cx; // cx is the constant

        i++;
    }
    return 0; // Inside the Julia set
}


// int main(void)
// {
//     double real_z, imag_z, real_c, imag_c;

//     // Kullanıcıdan z ve c karmaşık sayılarının reel ve sanal kısımlarını al
//     printf("Bir z karmaşık sayısının reel kısmını girin (real_z): ");
//     scanf("%lf", &real_z);
//     printf("Bir z karmaşık sayısının sanal kısmını girin (imag_z): ");
//     scanf("%lf", &imag_z);
//     printf("Bir c karmaşık sayısının reel kısmını girin (real_c): ");
//     scanf("%lf", &real_c);
//     printf("Bir c karmaşık sayısının sanal kısmını girin (imag_c): ");
//     scanf("%lf", &imag_c);

//     // Julia iterasyon sayısını hesapla
//     int result = julia_iterations(real_z, imag_z, real_c, imag_c, 60);
    
//     // Sonucu ekrana yazdır
//     if (result == 0) {
//         printf("Verilen z noktası Julia setindedir (yakınsama).\n");
//     } else {
//         printf("Verilen z noktası %d. iterasyonda divergent oldu.\n", result);
//     }

//     return 0;
// }
