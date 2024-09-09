/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:11:31 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/09 18:52:22 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_wspace_sign(char *s, int *sign)
{
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	while ((*s == '-' || *s == '+'))
	{
		if (*s == '-')
			*sign = -(*sign);
		s++;
	}
	if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
	{
		printf("error in atof\n");
		exit(1);
	}
	return (s);
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
	s = skip_wspace_sign(s, &sign);
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