/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 20:52:21 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	cylinder_intersect(t_data *data, t_geometry *cy)
{
	float	dist_quadra[2];
	int		dist;

	dist = cy_quadratic(data, cy, dist_quadra);
	if (dist == ERROR)
		return (-1);
	return (dist);
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
	{
		printf("tewG\n");
		return (1);
	}
	return (0);
}

int	get_color_cylinder(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	for_impact;

	new_color = 0;
	hit->geometry->dist_cam = cylinder_intersect(data, hit->geometry);
	if (hit->geometry->dist_cam < 0)
		return (new_color);
	vec_multiplying(&for_impact, &hit->geometry->ray.dir,
		hit->geometry->dist_cam);
	vec_add(&hit->geometry->impact_point, &data->scene->objects->ray.origin,
		&for_impact);
	printf("impact: %f, %f, %f\n", hit->geometry->impact_point.x,
		hit->geometry->impact_point.y, hit->geometry->impact_point.z);
	if (on_cy(hit->geometry))
		new_color = get_mix_color(data);
	return (new_color);
}

void	get_diffuse_light_cy(t_data *data, t_vector *color)
{
	t_vector	norm;
	float		ratio;

	vec_normalize(vec_subtract(&norm, &data->scene->objects->impact_point,
			&data->scene->objects->data.cylinder.center));
	vec_normalize(vec_subtract(&data->scene->objects->ray.light,
			&data->scene->objects->impact_point, &data->scene->light->origine));
	ratio = vec_dot_product(&norm, &data->scene->objects->ray.light);
	*color = (t_vector){0};
	if (ratio >= 0)
		vec_multiplying(color, &data->white_light, ratio);
}
