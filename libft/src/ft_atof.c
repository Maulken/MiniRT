/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:11:31 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/27 11:31:43 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

#define ERROR -1

static int	skip_wspace_sign(char *s, int *sign)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	while ((s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			*sign = -(*sign);
		i++;
	}
	if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
	{
		printf("error in atof\n");
		exit(1);
	}
	return (i);
}

static long	long_add(char *s, int *i)
{
	long	integer_part;

	integer_part = 0;
	while (s[*i] != '.' && s[*i])
	{
		if (integer_part > (LONG_MAX - (s[*i] - '0')) / 10)
		{
			printf("Error:overflow detected\n");
			return (ERROR);
		}
		integer_part = integer_part * 10 + s[*i] - '0';
		(*i)++;
	}
	return (integer_part);
}

double	ft_atof(char *s)
{
	long	integer_part;
	double	decimal_part;
	int		sign;
	double	div;
	int		i;

	integer_part = 0;
	decimal_part = 0;
	sign = 1;
	div = 1;
	i = skip_wspace_sign(s, &sign);
	integer_part = long_add(s, &i);
	if (integer_part == ERROR)
		return (ERROR);
	if (s[i] == '.')
		i++;
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		div /= 10;
		decimal_part = decimal_part + (s[i] - '0') * div;
		i++;
	}
	return ((integer_part + decimal_part) * sign);
}
