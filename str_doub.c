/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_doub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:53:04 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:14:09 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	parse_integer(const char *str, int *i)
{
	double	value;

	value = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		value = value * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (value);
}

double	parse_fraction(const char *str, int *i)
{
	double	value;
	double	weight;

	value = 0;
	weight = 1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			weight /= 10.0;
			value += (str[*i] - '0') * weight;
			(*i)++;
		}
	}
	return (value);
}

int	parse_exponent(const char *str, int *i)
{
	int	sign;
	int	exp;

	sign = 1;
	exp = 0;
	if (str[*i] == 'e' || str[*i] == 'E')
	{
		(*i)++;
		if (str[*i] == '-')
		{
			sign = -1;
			(*i)++;
		}
		else if (str[*i] == '+')
		{
			(*i)++;
		}
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			exp = exp * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
	return (sign * exp);
}

double	string_to_double(const char *str)
{
	int		i;
	int		sign;
	double	val;
	int		exp;

	i = 0;
	sign = 1;
	if (!str || str[0] == '\0')
		return (0.0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	val = parse_integer(str, &i) + parse_fraction(str, &i);
	exp = parse_exponent(str, &i);
	return (sign * val * power(10.0, exp));
}
