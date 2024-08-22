/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:50:39 by mpelluet          #+#    #+#             */
/*   Updated: 2024/08/20 15:51:24 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	*vec_add(t_vector *vec1, t_vector *vec2)
{
	t_vector	*result;

	result = new_vector(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z);
	return(result);
}

t_vector	*vec_multiplying(t_vector *vec1, float nbr)
{
	t_vector	*result;

	result = new_vector(vec1->x * nbr, vec1->y * nbr, vec1->z * nbr);
	return(result);
}

bool	vec_compare(t_vector *vec1, t_vector *vec2)
{
	if (vec1->x != vec2->x || (vec1->y != vec2->y) || (vec1->z != vec2->z))
		return (false);
	return (true);
}

t_vector	*vec_vec_multi(t_vector *vec1, t_vector *vec2)
{
	t_vector	*result;

	result = new_vector(
		vec1->x * vec2->x,
		vec1->y * vec2->y,
		vec1->z * vec2->z
	);
	return(result);
}
