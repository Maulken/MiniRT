/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:11:31 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/07 13:12:21 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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