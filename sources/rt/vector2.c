/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:50:39 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/07 13:45:35 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	vec_add(t_vector *vec1, t_vector *vec2)
{
	t_vector	result;

	result = new_vector(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
	return (result);
}

t_vector	vec_multiplying(t_vector *vec1, float nbr)
{
	t_vector	result;

	result = new_vector(vec1->x * nbr, vec1->y * nbr, vec1->z * nbr);
	return (result);
}

bool	vec_compare(t_vector *vec1, t_vector *vec2)
{
	if (vec1->x != vec2->x || (vec1->y != vec2->y) || (vec1->z != vec2->z))
		return (false);
	return (true);
}

t_vector	vec_vec_multi(t_vector *vec1, t_vector *vec2)
{
	t_vector	result;

	result = new_vector(
		vec1->x * vec2->x,
		vec1->y * vec2->y,
		vec1->z * vec2->z
	);
	return (result);
}

t_vector	vec_cross(t_vector *vec1, t_vector *vec2)
{
	float		x;
	float		y;
	float		z;
	t_vector	result;

	x = vec1->y * vec2->z - vec1->z * vec2->y;
	y = vec1->z * vec2->x - vec1->x * vec2->z;
	z = vec1->x * vec2->y - vec1->y * vec2->x;
	result = new_vector(x, y, z);
	return (result);
}
