/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   madelbrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:04:30 by beinan            #+#    #+#             */
/*   Updated: 2025/03/21 00:06:25 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <complex.h>

int mandelbrot_iterations(double real_c, double imag_c) 
{
    int i;
    double complex c = real_c + imag_c * I;
    double complex z = 0;
    int max_iterations = 50;

    i = 0;
    while (i < max_iterations) 
    {
        z = z * z + c;
        if (cabs(z) > 2)
            return i + 1;
        i++;
    }

    return 0;
}

int main() {
    double real_c, imag_c;

    printf("Bir karmaşık sayının reel kısmını girin (real_c): ");
    scanf("%lf", &real_c);
    printf("Bir karmaşık sayının sanal kısmını girin (imag_c): ");
    scanf("%lf", &imag_c);

    int result = mandelbrot_iterations(real_c, imag_c);
    
    if (result == 0) {
        printf("Verilen c noktası Mandelbrot setindedir (yakınsama).\n");
    } else {
        printf("Verilen c noktası %d. iterasyonda divergent oldu.\n", result);
    }

    return 0;
}
