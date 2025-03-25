/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beinan <beinan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:46:38 by beinan            #+#    #+#             */
/*   Updated: 2025/03/25 16:13:56 by beinan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_sign(const char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		(*i)++;
		return (1);
	}
	return (0);
}

int	parse_digits(const char *str, int *i, int *has_digit)
{
	int	start;

	start = *i;
	while (ft_isdigit(str[*i]))
	{
		*has_digit = 1;
		(*i)++;
	}
	return (*i > start);
}

int	parse_exponent2(const char *str, int *i)
{
	int	has_digit;

	if (str[*i] != 'e' && str[*i] != 'E')
		return (1);
	(*i)++;
	parse_sign(str, i);
	has_digit = 0;
	if (!parse_digits(str, i, &has_digit) || !has_digit)
		return (0);
	return (1);
}

int	is_valid_double(const char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (!str || str[0] == '\0')
		return (0);
	parse_sign(str, &i);
	parse_digits(str, &i, &has_digit);
	if (str[i] == '.')
	{
		i++;
		parse_digits(str, &i, &has_digit);
	}
	if (!has_digit || !parse_exponent2(str, &i))
		return (0);
	return (str[i] == '\0');
}
