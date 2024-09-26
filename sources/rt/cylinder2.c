/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:08:39 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:34 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	get_mix_color(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	if (hit->geometry->dist_cam <= 0)
		return (BACKGROUND_COLOR);
	mix_color = data->scene->ambient->ambient_light;
	get_diffuse_light_cy(data, &data->hit, &diffuse_light);
	if (diffuse_light.x)
	{
		vec_add(&mix_color, &data->scene->ambient->ambient_light,
			&diffuse_light);
	}
	vec_add(&mix_color, &data->hit.geometry->color, &mix_color);
	limit_color(&mix_color);
	new_color = create_rgb(&mix_color);
	return (new_color);
}

float	cy_quadratic(t_geometry *cy, float abc_value[3],
				t_vector *origin, t_vector *dir)
{
	t_vector	diff;
	t_vector	x_x_diff;
	t_vector	d_x_diff;
	float		discr;

	vec_subtract(&x_x_diff, origin, &cy->data.cylinder.center);
	vec_multiplying(&diff,
		&cy->data.cylinder.direction, -cy->data.cylinder.height);
	vec_cross(&x_x_diff, &x_x_diff, &diff);
	vec_cross(&d_x_diff, dir, &diff);
	abc_value[0] = vec_dot_product(&d_x_diff, &d_x_diff);
	abc_value[1] = 2. * vec_dot_product(&d_x_diff, &x_x_diff);
	abc_value[2] = vec_dot_product(&x_x_diff, &x_x_diff)
		- ((cy->data.cylinder.diameter / 2.) * (cy->data.cylinder.diameter / 2.)
			* vec_dot_product(&diff, &diff));
	discr = abc_value[1] * abc_value[1] - 4. * abc_value[0] * abc_value[2];
	if (discr < 0)
		return (ERROR);
	return (sqrtf(discr));
}
