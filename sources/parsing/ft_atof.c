/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:36:52 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 16:26:26 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	ft_atof_c_signe(const char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}


static int	ft_atof_next(const char *str, int result,
	int *decimal_point, double *fraction)
{
	*fraction = 1;
	while (ft_is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		if (*decimal_point == 1)
			return (1);
		str++;
		*decimal_point = 1;
	}
	while (ft_is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		*fraction *= 10;
		str++;
	}
	if (*decimal_point)
	{
		result /= *fraction;
	}
	return (result);
}

double	ft_atof_custom(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		decimal_point;
	int		i;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	i = 0;
	decimal_point = 0;
	i = ft_atof_c_signe(str, &sign);
	printf("signe %d\n", sign);
	printf("i %d\n", i);
	result = ft_atof_next(str + i, result, &decimal_point, &fraction);
	printf("result %f\n", result);
	return (sign * result);
}

static void	skip_wspace_sign(char *s, int *sign)
{
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while ((*s == '-' || *s == '+'))
	{
		if (*s == '-')
			*sign *= -1;
		s++;
	}
	if ((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122))
	{
		printf("error in atof\n");
		exit(1);
	}
}

double	ft_atof(char *s)
{
	long	integer_part;
	double	decimal_part;
	int		sign;
	double	div;

	integer_part = 0;
	decimal_part = 0;
	sign = 1;
	div = 1;
	skip_wspace_sign(s, &sign);
	while (*s != '.' && *s)
	{
		integer_part = integer_part * 10 + *s - '0';
		s++;
	}
	if (*s == '.')
		s++;
	while (*s && (*s >= 48 && *s <= 57))
	{
		div /= 10;
		decimal_part = decimal_part + (*s - '0') * div;
		s++;
	}
	return ((integer_part + decimal_part) * sign);
}
