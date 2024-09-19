/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/19 16:20:21 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	cylinder_intersect(t_geometry *cy, t_vector *origin, t_vector *dir)
{
	float	dist[2];
	float	math_value[3];
	int		discr;

	discr = cy_quadratic(cy, math_value, origin, dir);
	if (discr == ERROR)
		return (-1);
	dist[0] = (-math_value[1] + discr) / (2 * math_value[0]);
	dist[1] = (-math_value[1] - discr) / (2 * math_value[0]);
	if (dist[0] < dist[1])
		return (dist[0]);
	return (dist[1]);
}

float	on_cy(t_geometry *cy)
{
	t_vector	for_impact;
	float		dist;
	float		height_pos;
	float		pyth;

	vec_multiplying(&for_impact, &cy->ray.dir, cy->dist_cam);
	vec_add(&cy->impact_point, &cy->ray.origin, &for_impact);
	dist = sqrt(vec_dot_product(&cy->impact_point, &cy->data.cylinder.center));
	if (dist < 0)
		return (0);
	pyth = dist * dist;
	pyth -= cy->data.cylinder.diameter * cy->data.cylinder.diameter / 4.;
	if (pyth < 0)
		return (0);
	height_pos = sqrt(pyth);
	if (height_pos <= cy->data.cylinder.height / 2)
		return (1);
	return (0);
}

int	get_color_cylinder(t_data *data, t_hit *hit)
{
	//int	new_color;
//
//	new_color = 0;
//	if (hit->cylinder->dist_cam_cylinder >= 0)
//		new_color = get_mix_color(data);
//	return (new_color);
	int			new_color;
	t_vector	for_impact;

	new_color = 0x3300ff;
	hit->geometry->dist_cam = cylinder_intersect(hit->geometry,
			&hit->geometry->ray.origin, &hit->geometry->ray.dir);
	if (hit->geometry->dist_cam < 0)
		return (new_color);
	vec_multiplying(&for_impact, &hit->geometry->ray.dir,
		hit->geometry->dist_cam);
	vec_add(&hit->geometry->impact_point, &data->scene->objects->ray.origin,
		&for_impact);
	if (on_cy(hit->geometry))
		new_color = get_mix_color(data);
	return (new_color);
}

void	is_cylinder(t_data *data, t_scene tmp)
{
	float	dist;

	dist = cylinder_intersect(tmp.objects, &tmp.objects->ray.origin,
			&tmp.objects->ray.dir);
	if (dist < data->hit.distance && dist > 0)
	{
		data->hit.distance = dist;
		data->hit.geometry = tmp.objects;
	}
}
