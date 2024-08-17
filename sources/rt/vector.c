/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:12:17 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/17 19:21:56 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector *new_vector(float x, float y, float z)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	if(!vec)
		return(NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;

	return(vec);
}

t_vector *vec_subtract(t_vector *vec1, t_vector *vec2)
{
	t_vector	*result;

	result = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
	return(result);
}

float	vec_lenght(t_vector *vec1, t_vector *vec2)
{
	float result;

	result = sqrt((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return(result);
}

void	vec_normalize(t_vector *vec)
{
	float	lenght;

	lenght = vec_lenght(vec, vec);
	vec->x /= lenght;
	vec->y /= lenght;
	vec->z /= lenght;
}

float	vec_dot_product(t_vector *vec1, t_vector *vec2)
{
	float	result;

	result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return(result);
}

