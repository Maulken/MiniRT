/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/25 17:41:51 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define NEAR 0.01
#define FAR 250.0

float	dist_cy(t_geometry *cy, float dist0, float dist1, t_vector *origin, t_vector *dir)
{
	t_vector	for_impact;

	if (dist0 >= NEAR && dist0 <= FAR)
	{
		vec_multiplying(&for_impact, dir, dist0);
		vec_add(&cy->impact_point, origin, &for_impact);
		if (on_cy(cy))
		{
			cy->in_out = OUTSIDE;
			return (dist0);
		}
	}
	if (dist1 >= NEAR && dist1 <= FAR)
	{
		vec_multiplying(&for_impact, dir, dist1);
		vec_add(&cy->impact_point, origin, &for_impact);
		if (on_cy(cy))
		{
			cy->in_out = INSIDE;
			return (dist1);
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
	return (dist_cy(cy, dist[0], dist[1], origin, dir));
}

float	on_cy(t_geometry *cy)
{
	t_vector	for_impact;
	// float		dist;
	// float		height_pos;
	float		pyth;

	// vec_multiplying(&for_impact, &cy->ray.dir, cy->dist_cam);
	// vec_add(&cy->impact_point, &cy->ray.origin, &for_impact);
	// pyth = vec_dot_product(&cy->impact_point, &cy->data.cylinder.center);
	pyth = vec_length2(vec_subtract(&for_impact, &cy->impact_point,
			&cy->data.cylinder.center));
	pyth -= cy->data.cylinder.diameter * cy->data.cylinder.diameter / 4.;
	if (pyth < 0)
		return (0);
	// height_pos = sqrt(pyth);
	if (pyth <= cy->data.cylinder.height * cy->data.cylinder.height / 4.)
		return (1);
	return (0);
}
int	get_caps_top(t_hit *hit)
{
	t_vector	top_cap;
	// t_vector	bottom_cap;
	t_vector	cy_size;
	//t_vector	pl_cy;
	t_vector	hit_cy;
	t_geometry	pl;
	float		dist;

	pl.data.plane.direction = hit->geometry->data.cylinder.direction;
	vec_add(&top_cap, &hit->geometry->data.cylinder.center,
		vec_multiplying(&top_cap, &hit->geometry->data.cylinder.direction,
		(hit->geometry->data.cylinder.height / 2)));
	pl.data.plane.origine = top_cap;
	vec_multiplying(&hit_cy, &pl.data.plane.direction,
		plane_intersect(&pl, &hit->geometry->ray.origin,
		&hit->geometry->ray.dir));
    vec_add(&hit_cy, &pl.data.plane.origine, &hit_cy);
	dist = vec_lenght(vec_subtract(&cy_size, &hit_cy, &pl.data.plane.origine));
	if (dist <= (hit->geometry->data.cylinder.diameter / 2))
		return (1);
	return (0);
	// vec_subtract(&bottom_cap, &cy->center,
	// 	vec_multiplying(&cy_size, &cy->direction, (cy->height / 2)));

}
int	get_caps_bottom(t_hit *hit)
{
	// t_vector	top_cap;
	t_vector	bottom_cap;
	t_vector	cy_size;
	//t_vector	pl_cy;
	t_vector	hit_cy;
	t_geometry	pl;
	float		dist;

	pl.data.plane.direction = hit->geometry->data.cylinder.direction;
	vec_add(&bottom_cap, &hit->geometry->data.cylinder.center,
		vec_multiplying(&bottom_cap, &hit->geometry->data.cylinder.direction,
		(hit->geometry->data.cylinder.height / (-2))));
	pl.data.plane.origine = bottom_cap;
	vec_multiplying(&hit_cy, &pl.data.plane.direction,
		plane_intersect(&pl, &hit->geometry->ray.origin,
		&hit->geometry->ray.dir));
    vec_add(&hit_cy, &pl.data.plane.origine, &hit_cy);
	dist = vec_lenght(vec_subtract(&cy_size, &hit_cy, &pl.data.plane.origine));
	if (dist <= (hit->geometry->data.cylinder.diameter / 2))
		return (1);
	return (0);
	// vec_subtract(&bottom_cap, &cy->center,
	// 	vec_multiplying(&cy_size, &cy->direction, (cy->height / 2)));

}
// int	get_color_cylinder(t_data *data, t_hit *hit)
// {
// 	int			new_color;
// 	// t_vector	for_impact;

// 	(void)hit;
// 	new_color = 0x3300ff;
// 	// hit->geometry->dist_cam = cylinder_intersect(hit->geometry);
// 	// if (hit->geometry->dist_cam <= 0)
// 		// return (new_color);
// 	// if (on_cy(hit->geometry) && get_caps_bottom(hit) && get_caps_top(hit))
// 	// if (on_cy(hit->geometry))
// 		new_color = get_mix_color(data);
// 	// else if (on_cy(hit->geometry) == 0)
// 	// 	new_color = 0x3300ff;
// 	// vec_multiplying(&for_impact, &hit->geometry->ray.dir,
// 	// 	hit->geometry->dist_cam);
// 	// vec_add(&hit->geometry->impact_point, &data->scene->objects->ray.origin,
// 	// 	&for_impact);
// 	return (new_color);
// }

//we are just checking if we are on the infinite cylinder, we should check on_cy
//here
// void	is_cylinder(t_data *data, t_scene tmp)
// {
// 	float	dist;

// 	dist = cylinder_intersect(tmp.objects, &tmp.objects->ray.origin,
// 			&tmp.objects->ray.dir);
// 	if (dist < data->hit.distance && dist > 0 && on_cy(tmp.objects) == 1)
// 	{
// 		data->hit.distance = dist;
// 		data->hit.geometry = tmp.objects;
// 	}
// }
void	is_cylinder(t_data *data, t_scene tmp)
{
	t_vector	for_impact;

	tmp.objects->dist_cam = cylinder_intersect(tmp.objects,
			&tmp.objects->ray.origin, &tmp.objects->ray.dir);
	// if (tmp.objects->dist_cam != -1)
	// 	printf("dist cam %f\n", tmp.objects->dist_cam);
	if (tmp.objects->dist_cam < data->hit.distance
		&& (tmp.objects->dist_cam) > 0)
		// && on_cy(tmp.objects) == 1)
	{
		// printf("ici\n");
		data->hit.distance = tmp.objects->dist_cam;
		data->hit.geometry = tmp.objects;
		vec_multiplying(&for_impact, &data->hit.geometry->ray.dir,
			data->hit.geometry->dist_cam);
		vec_add(&data->hit.geometry->impact_point,
			&data->hit.geometry->ray.origin, &for_impact);
	}
}
