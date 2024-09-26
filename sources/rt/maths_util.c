/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:45:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/26 14:53:06 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	quadratic_equation(float t[2], float a, float b, float c)
{
	float	discr;

	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (ERROR);
	discr = sqrtf(discr);
	t[0] = (-b - discr) / (2 * a);
	t[1] = (-b + discr) / (2 * a);
	return (OK);
}

float	ft_square(float a)
{
	return (a * a);
}

float	checking_limit(float a, int min, int max)
{
	if (a < min)
		return (1);
	if (a > max)
		return (1);
	return (a);
}
