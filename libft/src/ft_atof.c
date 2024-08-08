/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:02:21 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/03 15:37:37 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
	int		w;
	double	d;
	int		neg;

	w = 0;
	neg = 1;
	if (*str == '-' && ((*str)++))
		neg = -1;
	while (ft_isdigit(*str))
		w = w * 10 + (((*str)++) - '0');
	if (*str == '.')
		(*str)++;
	d = 0.0;
	while (ft_isdigit(*str))
		d = d * 10 + (((*str)++) - '0');
	while (d >= 1)
		d /= 10;
	d += w;
	next(str);
	return (d * neg);
}
