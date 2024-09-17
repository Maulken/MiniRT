/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:12:17 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:23:30 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	*vec_subtract(t_vector *dst, t_vector *vec1, t_vector *vec2)
{
	dst->x = vec1->x - vec2->x;
	dst->y = vec1->y - vec2->y;
	dst->z = vec1->z - vec2->z;
	return (dst);
}

float	vec_length2(t_vector *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

float	vec_lenght(t_vector *vec)
{
	return (sqrt(vec_length2(vec)));
}

t_vector	*vec_normalize(t_vector *vec)
{
	float	lenght;

	lenght = vec_lenght(vec);
	vec->x /= lenght;
	vec->y /= lenght;
	vec->z /= lenght;
	return (vec);
}

float	vec_dot_product(t_vector *vec1, t_vector *vec2)
{
	float	result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (result);
}
