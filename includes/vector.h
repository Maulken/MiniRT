/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:20:00 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/12 15:22:24 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

t_vector	*vec_subtract(t_vector *dst, t_vector *vec1, t_vector *vec2);
t_vector	*vec_normalize(t_vector *vec);
t_vector	*vec_add(t_vector *dst, t_vector *vec1, t_vector *vec2);
t_vector	*vec_multiplying(t_vector *dst, t_vector *vec, float nbr);
t_vector	*vec_cross(t_vector *dst, t_vector *vec1, t_vector *vec2);
float		vec_length2(t_vector *vec);
float		vec_lenght(t_vector *vec);
float		vec_dot_product(t_vector *vec1, t_vector *vec2);
bool		vec_compare(t_vector *vec1, t_vector *vec2);

#endif