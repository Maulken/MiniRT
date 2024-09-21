/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:08:39 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/21 15:59:49 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// int	get_pl_intersect(t_data *data, t_geometry *cy)
// {
// 	t_vector	pl_center;
// 	t_vector	pl_cam;
// 	float		num;
// 	float		den;

// 	den = vec_dot_product(
// 			&data->scene->objects->ray.origin, &cy->data.cylinder.direction);
// 	if (den == 0)
// 		return (-1);
// 	vec_multiplying(&pl_center,
// 		&cy->data.cylinder.center, cy->data.cylinder.height / 2);
// 	vec_subtract(&pl_cam, &data->scene->camera->origine, &pl_center);
// 	num = vec_dot_product(&pl_cam, &cy->data.cylinder.direction);
// 	return (num / den);
// }

// int	add_plane(t_data *data, t_geometry *cy)
// {
// 	t_vector	pl_center;
// 	t_vector	for_impact;
// 	t_vector	pl_impact;
// 	float		dist;
// 	int			new_color;

// 	new_color = 0;
// 	vec_multiplying(&pl_center,
// 		&cy->data.cylinder.center, cy->data.cylinder.height / 2);
// 	vec_multiplying(&for_impact, &cy->ray.origin, get_pl_intersect(data, cy));
// 	vec_add(&pl_impact, &data->scene->camera->origine, &for_impact);
// 	dist = sqrt(vec_dot_product(&pl_impact, &pl_center));
// 	if (dist < cy->data.cylinder.diameter / 2)
// 		new_color = get_mix_color(data);
// 	return (new_color);
// }

int	get_mix_color(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	hit->geometry->dist_cam = cylinder_intersect(hit->geometry,
			&hit->geometry->ray.origin, &hit->geometry->ray.dir);
	if (hit->geometry->dist_cam <= 0)
		return (0x3300ff);
	mix_color = data->scene->ambient->ambient_light;
	// printf("\e[35mimpact point %f\e[0m\n", data->hit.geometry->impact_point.x);
	get_diffuse_light_cy(data, &data->hit, &diffuse_light);
	if (diffuse_light.x)
	{
		// printf("rlg\n");
		vec_add(&mix_color, &data->scene->ambient->ambient_light,
			&diffuse_light);
	}
	vec_add(&mix_color, &data->hit.geometry->color, &mix_color);
	limit_color(&mix_color);
	new_color = create_rgb(&mix_color);
	return (new_color);
}

int	cy_quadratic(t_geometry *cy, float math_value[3],
				t_vector *origin, t_vector *dir)
{
	t_vector	diff;
	t_vector	x_x_diff;
	t_vector	d_x_diff;
	float		discr;

	vec_subtract(&x_x_diff, origin, &cy->data.cylinder.center);
	vec_multiplying(&diff,
		&cy->data.cylinder.direction, cy->data.cylinder.height);
	vec_add(&diff, &cy->data.cylinder.center, &diff);
	vec_subtract(&diff, &cy->data.cylinder.center, &diff);
	vec_cross(&x_x_diff, &x_x_diff, &diff);
	vec_cross(&d_x_diff, dir, &diff);
	math_value[0] = vec_dot_product(&d_x_diff, &d_x_diff);
	math_value[1] = 2 * vec_dot_product(&d_x_diff, &x_x_diff);
	math_value[2] = vec_dot_product(&x_x_diff, &x_x_diff)
		- ((cy->data.cylinder.diameter / 2) * (cy->data.cylinder.diameter / 2)
			* vec_dot_product(&diff, &diff));
	discr = math_value[1] * math_value[1] - 4 * math_value[0] * math_value[2];
	if (discr < 0)
		return (ERROR);
	discr = sqrtf(discr);
	return (discr);
}
