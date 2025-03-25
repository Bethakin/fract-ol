/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:42:40 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 14:54:31 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char *ft_lowerall(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        str[i] = ft_tolower(str[i]);
        i++;
    }
    return (str);
}


int is_it_mandel(int ac, char **ag)
{
    if(ac == 2)
    {
        if(ft_strncmp(ft_lowerall(ag[1]),"mandelbrot", 11) == 0)
            return (1);
        else
            return (0);
    }
    return (0);
}



#include <stdio.h>
#include <float.h> // For DBL_MIN and DBL_MAX

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}


int is_valid_double(const char *str)
{
    int i = 0;
    int has_digit = 0;
    int has_dot = 0;
    int has_exp = 0;
    int sign = 0;

    if (str == NULL || *str == '\0')
        return 0;
    if (str[i] == '+' || str[i] == '-')
    {
        sign = 1;
        i++;
    }
    double integer_part = 0.0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        has_digit = 1;
        integer_part = integer_part * 10 + (str[i] - '0');
        i++;
    }
    double fractional_part = 0.0;
    double fractional_weight = 1.0;
    if (str[i] == '.') 
    {
        has_dot = 1;
        i++;
        while (str[i] >= '0' && str[i] <= '9') 
        {
            has_digit = 1;
            fractional_weight /= 10.0;
            fractional_part += (str[i] - '0') * fractional_weight;
            i++;
        }
    }
    int exp_sign = 1;
    int exponent = 0;
    if (str[i] == 'e' || str[i] == 'E') 
    {
        has_exp = 1;
        i++;
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-')
                exp_sign = -1;
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9') 
        {
            exponent = exponent * 10 + (str[i] - '0');
            i++;
        }
    }
    if (str[i] != '\0')
        return 0;
    if (!has_digit)
        return 0;
    double value = (integer_part + fractional_part) * power(10.0, exp_sign * exponent);
    if (value < -DBL_MAX || value > DBL_MAX)
        return 0;
    return 1;
}
double string_to_double(const char *str)
{
    int i = 0;
    int sign = 1;
    double integer_part = 0.0;
    double fractional_part = 0.0;
    double fractional_weight = 1.0;
    int exponent = 0;
    int exp_sign = 1;

    if (str == NULL || *str == '\0')
        return 0.0;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        integer_part = integer_part * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.') {
        i++;
        while (str[i] >= '0' && str[i] <= '9') {
            fractional_weight /= 10.0;
            fractional_part += (str[i] - '0') * fractional_weight;
            i++;
        }
    }
    if (str[i] == 'e' || str[i] == 'E') {
        i++;
        if (str[i] == '+' || str[i] == '-') {
            if (str[i] == '-') {
                exp_sign = -1;
            }
            i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
            exponent = exponent * 10 + (str[i] - '0');
            i++;
        }
    }
    double value = (integer_part + fractional_part) * power(10.0, exp_sign * exponent);
    return sign * value;
}

int is_it_julia(int ac, char **ag)
{
    if(ac == 2)
    {
        if(ft_strncmp(ft_lowerall(ag[1]),"julia", 6) == 0)
            return (1);
        else
            return (0);
    }
    else if (ac == 4)
    {
        if(ft_strncmp(ft_lowerall(ag[1]),"julia", 6) == 0 && is_valid_double(ag[2]) == 1 && is_valid_double(ag[3]) == 1)
            return (1);
        else
            return (0);
    } //SAYILARI KONTROL ETMEDİM
    return (0);
}

int is_error(int ac, char **ag, t_fractol *f) 
{
    if(is_it_mandel(ac, ag) == 1)
    {
        f->name = 'm';
        f->x = 0;
        f->y = 0;
        f->color = 0x0721FF;
        f->iter = 35;
        f->zoom = 350;
        // f->offset_x = -1.21;
	    // f->offset_y = -1.21;
        return (1);
    }  
    if (is_it_julia(ac, ag) == 1 && ac == 4)
    {
        f->name = 'j';
        f->x = 0;
        f->y = 0;
        f->cx = string_to_double(ag[2]);
        f->cy = string_to_double(ag[3]);
        f->color = 0x0721FF;
        f->iter = 35;
		// f->cx = -0.7;
		// f->cy = 0.23;
        f->zoom = 350;
        // f->offset_x = -1.21;
	    // f->offset_y = -1.21;
        return (1);
    } 
    if (is_it_julia(ac, ag) == 1 && ac == 2)
    {
        f->name = 'j';
        f->x = 0;
        f->y = 0;
        // f->cx = string_to_double(ag[2]);
        // f->cy = string_to_double(ag[3]);
        f->color = 0x0721FF;
        f->iter = 35;
		f->cx = -0.7;
		f->cy = 0.23;
        f->zoom = 350;
        // f->offset_x = -1.21;
	    // f->offset_y = -1.21;
        return (1);
    }
    return (0);
}
