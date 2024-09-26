/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:28 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define NEAR 0.01
#define FAR 250.0

static float	dist_cy(t_geometry *cy, float dist[2], t_vector *origin,
			t_vector *dir)
{
	t_vector	for_impact;

	if (dist[0] >= NEAR && dist[0] <= FAR)
	{
		vec_multiplying(&for_impact, dir, dist[0]);
		vec_add(&cy->impact_point, origin, &for_impact);
		if (on_cy(cy))
		{
			cy->in_out = OUTSIDE;
			return (dist[0]);
		}
	}
	if (dist[1] >= NEAR && dist[1] <= FAR)
	{
		vec_multiplying(&for_impact, dir, dist[1]);
		vec_add(&cy->impact_point, origin, &for_impact);
		if (on_cy(cy))
		{
			cy->in_out = INSIDE;
			return (dist[1]);
		}
	}
	return (-1);
}

float	cylinder_intersect(t_geometry *cy, t_vector *origin, t_vector *dir)
{
	float	dist[2];
	float	abc_value[3];
	float	discr;

	discr = cy_quadratic(cy, abc_value, origin, dir);
	if (discr == ERROR)
		return (-1);
	dist[0] = (-abc_value[1] - discr) / (2 * abc_value[0]);
	dist[1] = (-abc_value[1] + discr) / (2 * abc_value[0]);
	return (dist_cy(cy, dist, origin, dir));
}

float	on_cy(t_geometry *cy)
{
	t_vector	for_impact;
	float		pyth;

	pyth = vec_length2(vec_subtract(&for_impact, &cy->impact_point,
				&cy->data.cylinder.center));
	pyth -= cy->data.cylinder.diameter * cy->data.cylinder.diameter / 4.;
	if (pyth < 0)
		return (0);
	if (pyth <= cy->data.cylinder.height * cy->data.cylinder.height / 4.)
		return (1);
	return (0);
}

void	is_cylinder(t_data *data, t_scene tmp)
{
	t_vector	for_impact;

	tmp.objects->dist_cam = cylinder_intersect(tmp.objects,
			&tmp.objects->ray.origin, &tmp.objects->ray.dir);
	if (tmp.objects->dist_cam < data->hit.distance
		&& (tmp.objects->dist_cam) > 0)
	{
		data->hit.distance = tmp.objects->dist_cam;
		data->hit.geometry = tmp.objects;
		vec_multiplying(&for_impact, &data->hit.geometry->ray.dir,
			data->hit.geometry->dist_cam);
		vec_add(&data->hit.geometry->impact_point,
			&data->hit.geometry->ray.origin, &for_impact);
	}
}
