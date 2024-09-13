/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:08:39 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:28:25 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	get_pl_intersect(t_data *data, t_cylinder *cy)
{
	t_vector	pl_center;
	t_vector	pl_cam;
	float		num;
	float		den;
	float		dist;

	pl_center = vec_multiplying(cy->center, cy->height / 2);
	pl_cam = vec_subtract(data->scene->camera->origine, &pl_center);
	num = vec_dot_product(&pl_cam, cy->direction);
	den = vec_dot_product(data->scene->plane->ray, cy->direction);
	if (den != 0.0)
	{
		dist = num / den;
		return(dist);
	}
	return (-1);
}

int	add_plane(t_data *data, t_cylinder *cy)
{
	t_vector	pl_center;
	t_vector	for_impact;
	t_vector	pl_impact;
	float		dist;
	int			new_color;

	new_color = 0;
	pl_center = vec_multiplying(cy->center, cy->height / 2);
	for_impact = vec_multiplying(cy->ray, get_pl_intersect(data, cy));
	pl_impact = vec_add(data->scene->camera->origine, &for_impact);
	dist = vec_lenght(&pl_impact, &pl_center);
	if (dist < cy->diameter / 2)
		new_color = get_mix_color(data);
	return (new_color);
}

int	get_mix_color(t_data *data)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	mix_color = *data->scene->ambient->ambient_light;
	diffuse_light = get_diffuse_light_cy(data);
	if (diffuse_light.x)
		mix_color = vec_add(data->scene->ambient->ambient_light,
		&diffuse_light);
	mix_color = vec_add(data->hit->cylinder->color, &mix_color);
	limit_color(&mix_color);
	new_color = create_rgb(&mix_color);
	return (new_color);
}
int	cy_quadratic(t_data *data, t_cylinder *cy, float dist[2])
{
	/*float		radius;
	t_vector	x;
	t_vector	diff;
	t_vector	x_x_diff;
	t_vector	d_x_diff;
	t_vector	add;
	t_vector	mult;
	float		a;
	float		b;
	float		c;
	float		discr;
	(void)data;

	x = vec_subtract(cy->ray, cy->center);
	mult = vec_multiplying(cy->direction, cy->height);
	add = vec_add(cy->center, &mult);
	diff = vec_subtract(cy->center, &add);
	x_x_diff = vec_cross(&x, &diff);
	d_x_diff = vec_cross(cy->ray_dir, &diff);
	radius = vec_dot_product(&diff, &diff);
	a = vec_dot_product(&d_x_diff, &d_x_diff);
	b = 2 * vec_dot_product(&d_x_diff, &x_x_diff);
	c = vec_dot_product(&x_x_diff, &x_x_diff) - ((cy->diameter / 2) *
		(cy->diameter / 2) * radius);
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (ERROR);
	discr = sqrtf(discr);
	dist[0] = (-b - discr) / (2 * a);
	dist[1] = (-b + discr) / (2 * a);
	if (dist[0] < dist[1])
			return (dist[0]);
	return (dist[1]);
	*/
		t_vector	diff;
	t_vector	x_x_diff;
	t_vector	d_x_diff;
	float		discr;

	(void)data;
	vec_subtract(&x_x_diff, &cy->ray.origin, &cy->data.cylinder.center);
	vec_multiplying(&diff,
		&cy->data.cylinder.direction, cy->data.cylinder.height);
	vec_add(&diff, &cy->data.cylinder.center, &diff);
	vec_subtract(&diff, &cy->data.cylinder.center, &diff);
	vec_cross(&x_x_diff, &x_x_diff, &diff);
	vec_cross(&d_x_diff, &cy->ray.dir, &diff);
	discr = vec_length2(&d_x_diff) * vec_length2(&diff)
		* cy->data.cylinder.diameter * cy->data.cylinder.diameter;
	if (discr < 0)
		return (ERROR);
	discr = sqrtf(discr);
	if (dist[0] < dist[1])
		return (dist[0]);
	return (dist[1]);
}

