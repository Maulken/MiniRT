/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:36:52 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/20 10:37:50 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int ft_atof_c_signe(const char *str , int *sign)
{
	int i = 0 ;
if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return(i);
}

static int ft_atof_next(const char *str , int result, int decimal_point , int fraction)
{
	while (ft_is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		if (decimal_point == 1)
			return (1);
		str++;
		decimal_point = 1;
	}
	while (ft_is_digit(*str))
	{
		result = result * 10 + (*str - '0');
		fraction *= 10;
		str++;
	}
	if (decimal_point)
	{
		result /= fraction;
	}
	return(result);
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
	result = ft_atof_next(str, result, decimal_point, fraction);
	return (sign * result);
}