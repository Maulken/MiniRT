/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:45:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/05 18:12:59 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	quadratic_equation(float t[2], float a, float b, float c)
{
	float	discr;

	discr = (b * b) - (4 * a * c);
	// printf("discr = %f\n", discr);
	if (discr < 0)
		return (EXIT_FAILURE);
	discr = sqrtf(discr);
	t[0] = (-b - discr) / (2 * a);
	t[1] = (-b + discr) / (2 * a);
	return (EXIT_SUCCESS);
}

float	ft_square(float a)
{
	return (a * a);
}

float	checking_limit(float a, float min, float max)
{
	if (a < min)
		return (min);
	if (a > max)
		return (max);
	return (a);
}
