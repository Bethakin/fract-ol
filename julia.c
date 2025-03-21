/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:18:28 by beinan            #+#    #+#             */
/*   Updated: 2025/03/21 01:23:50 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <complex.h> 

int julia_iterations(double real_z, double imag_z, double real_c, double imag_c) {
    // Karmaşık sayı z = real_z + imag_z * i
    // Karmaşık sayı c = real_c + imag_c * i
    int i = 0;
    double complex z = real_z + imag_z * I;
    double complex c = real_c + imag_c * I;
    int max_iterations = 50;

    while (i < max_iterations)
    {
        z = z * z + c;
        if (cabs(z) > 2)
        {
            return i + 1;
        }
        i++;
    }

    return 0;
}

int main(void)
{
    double real_z, imag_z, real_c, imag_c;

    // Kullanıcıdan z ve c karmaşık sayılarının reel ve sanal kısımlarını al
    printf("Bir z karmaşık sayısının reel kısmını girin (real_z): ");
    scanf("%lf", &real_z);
    printf("Bir z karmaşık sayısının sanal kısmını girin (imag_z): ");
    scanf("%lf", &imag_z);
    printf("Bir c karmaşık sayısının reel kısmını girin (real_c): ");
    scanf("%lf", &real_c);
    printf("Bir c karmaşık sayısının sanal kısmını girin (imag_c): ");
    scanf("%lf", &imag_c);

    // Julia iterasyon sayısını hesapla
    int result = julia_iterations(real_z, imag_z, real_c, imag_c);
    
    // Sonucu ekrana yazdır
    if (result == 0) {
        printf("Verilen z noktası Julia setindedir (yakınsama).\n");
    } else {
        printf("Verilen z noktası %d. iterasyonda divergent oldu.\n", result);
    }

    return 0;
}
