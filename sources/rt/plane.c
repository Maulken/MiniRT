/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:11:07 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/20 11:12:02 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	plane_intersect(t_geometry *pl, t_vector *origin, t_vector *dir)
{
	t_vector	v;
	float		d;

	d = vec_dot_product(&pl->data.plane.direction, dir);
	if (d <= 0)
		return (-1);
	vec_subtract(&v, &pl->data.plane.origine, origin);
	d = vec_dot_product(&v, &pl->data.plane.direction) / d;
	if (d < 0)
		return (0);
	return (d);
}

int	get_color_plane(t_data *data)
{
	t_vector	diffuse_light;
	t_vector	mix_color;

	data->hit.geometry->dist_cam = plane_intersect(data->hit.geometry,
			&data->hit.geometry->ray.origin, &data->hit.geometry->ray.dir);
	mix_color = data->scene->ambient->ambient_light;
	get_diffuse_light_pl(data, &data->hit, &diffuse_light);
	if (diffuse_light.x)
		vec_add(&mix_color, &data->scene->ambient->ambient_light,
			&diffuse_light);
	vec_add(&mix_color, &data->hit.geometry->color, &mix_color);
	limit_color(&mix_color);
	return (create_rgb(&mix_color));
}

void	is_plane(t_data *data, t_scene tmp)
{
	float	dist;

	dist = plane_intersect(tmp.objects, &tmp.objects->ray.origin,
			&tmp.objects->ray.dir);
	if (dist < data->hit.distance && dist > 0)
	{
		data->hit.distance = dist;
		data->hit.geometry = tmp.objects;
	}
}
