/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:50:39 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/12 13:32:01 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	*vec_add(t_vector *dst, t_vector *vec1, t_vector *vec2)
{
	dst->x = vec1->x + vec2->x;
	dst->y = vec1->y + vec2->y;
	dst->z = vec1->z + vec2->z;
	return (dst);
}

t_vector	*vec_multiplying(t_vector *dst, t_vector *vec, float nbr)
{
	dst->x = vec->x * nbr;
	dst->y = vec->y * nbr;
	dst->z = vec->z * nbr;
	return (dst);
}

bool	vec_compare(t_vector *vec1, t_vector *vec2)
{
	if (vec1->x != vec2->x || (vec1->y != vec2->y) || (vec1->z != vec2->z))
		return (false);
	return (true);
}

t_vector	*vec_cross(t_vector *dst, t_vector *vec1, t_vector *vec2)
{
	float		x;
	float		y;
	float		z;

	x = vec1->y * vec2->z - vec1->z * vec2->y;
	y = vec1->z * vec2->x - vec1->x * vec2->z;
	z = vec1->x * vec2->y - vec1->y * vec2->x;
	dst->x = x;
	dst->y = y;
	dst->z = z;
	return (dst);
}
