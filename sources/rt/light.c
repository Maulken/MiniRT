/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:43:58 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/19 16:15:36 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static bool	is_obstacle(t_scene tmp, t_hit *hit)
{
	t_vector	ray;

	if (hit->geometry->type == GT_SPHERE)
		ray = hit->geometry->ray.light;
	else
		vec_multiplying(&ray, &hit->geometry->ray.light, -1.);
	while (tmp.objects)
	{
		if (tmp.objects->type == GT_SPHERE
			&& sphere_intersect(tmp.objects,
				&hit->geometry->impact_point, &ray) > 0)
			return (true);
		else if (tmp.objects->type == GT_PLANE
			&& plane_intersect(tmp.objects,
				&hit->geometry->impact_point, &ray) > 0)
			return (true);
		else if (tmp.objects->type == GT_CYLINDER
			&& cylinder_intersect(tmp.objects,
				&hit->geometry->impact_point, &ray) > 0)
			return (true);
		tmp.objects = tmp.objects->next;
	}
	return (false);
}

void	get_diffuse_light_sp(t_data *data, t_hit *hit, t_vector *color)
{
	t_vector	norm;
	t_vector	for_impact;
	float		ratio;

	*color = (t_vector){0};
	vec_add(&hit->geometry->impact_point,
		&hit->geometry->ray.origin,
		vec_multiplying(&for_impact,
			&hit->geometry->ray.dir, hit->geometry->dist_cam));
	vec_normalize(vec_subtract(&hit->geometry->ray.light,
			&data->scene->light->origine, &hit->geometry->impact_point));
	if (is_obstacle(*data->scene, hit) == false)
	{
		vec_normalize(vec_subtract(&norm, &hit->geometry->impact_point,
				&hit->geometry->data.sphere.center));
		ratio = vec_dot_product(&norm, &hit->geometry->ray.light);
		if (ratio >= 0)
			vec_multiplying(color, &data->white_light, ratio);
	}
}

void	get_diffuse_light_pl(t_data *data, t_hit *hit, t_vector *color)
{
	t_vector	for_impact;
	float		ratio;

	*color = (t_vector){0};
	vec_add(&hit->geometry->impact_point,
		&hit->geometry->ray.origin,
		vec_multiplying(&for_impact,
			&hit->geometry->ray.dir, hit->geometry->dist_cam));
	vec_normalize(vec_subtract(&hit->geometry->ray.light,
			&hit->geometry->impact_point, &data->scene->light->origine));
	if (is_obstacle(*data->scene, hit) == false)
	{
		ratio = vec_dot_product(&hit->geometry->data.plane.direction,
				&hit->geometry->ray.light);
		if (ratio >= 0)
			vec_multiplying(color, &data->white_light, ratio);
	}
}

void	get_diffuse_light_cy(t_data *data, t_vector *color)
{
	t_vector	norm;
	float		ratio;

	*color = (t_vector){0};
	vec_normalize(vec_subtract(&data->scene->objects->ray.light,
			&data->scene->objects->impact_point, &data->scene->light->origine));
	if (is_obstacle(*data->scene, &data->hit) == false)
	{
		vec_normalize(vec_subtract(&norm, &data->scene->objects->impact_point,
				&data->scene->objects->data.cylinder.center));
		ratio = vec_dot_product(&norm, &data->scene->objects->ray.light);
		if (ratio >= 0)
			vec_multiplying(color, &data->white_light, ratio);
	}
}
