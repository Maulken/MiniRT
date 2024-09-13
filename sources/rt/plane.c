/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:11:07 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 20:43:06 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	plane_intersect(t_data *data, t_geometry *pl)
{
	t_vector	v;
	float		d;

	(void)data;
	d = vec_dot_product(&pl->data.plane.direction, &pl->ray.dir);
	if (d <= 0)
		return (-1);
	vec_subtract(&v, &pl->data.plane.origine, &pl->ray.origin);
	d = vec_dot_product(&v, &pl->data.plane.direction) / d;
	return (d);
}

int	get_color_plane(t_data *data)
{
	t_vector	diffuse_light;
	t_vector	mix_color;

	data->scene->objects->dist_cam
		= plane_intersect(data, data->scene->objects);
	if (data->scene->objects->dist_cam < 0)
		return (0);
	mix_color = data->scene->ambient->ambient_light;
	get_diffuse_light_pl(data, &diffuse_light);
	if (diffuse_light.x)
		vec_add(&mix_color, &data->scene->ambient->ambient_light,
			&diffuse_light);
	vec_add(&mix_color, &data->scene->objects->color, &mix_color);
	limit_color(&mix_color);
	return (create_rgb(&mix_color));
}

void	get_diffuse_light_pl(t_data *data, t_vector *color) // a check origine
{
	t_vector	norm;
	t_vector	for_impact;
	float		ratio;

	vec_multiplying(&for_impact, &data->scene->objects->ray.origin,
		data->scene->objects->dist_cam);
	vec_add(&data->scene->objects->impact_point, &data->scene->camera->origine,
		&for_impact);
	vec_normalize(vec_subtract(&norm, &data->scene->objects->impact_point,
			&data->scene->objects->data.plane.origine));
	vec_normalize(vec_subtract(&data->scene->objects->ray.light,
			&data->scene->objects->impact_point, &data->scene->light->origine));
	ratio = vec_dot_product(&norm, &data->scene->objects->ray.light);
	*color = (t_vector){0};
	if (ratio >= 0)
		vec_multiplying(color, &data->white_light, ratio);
}
