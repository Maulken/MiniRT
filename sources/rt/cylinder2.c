/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:08:39 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 11:04:18 by vmassoli         ###   ########.fr       */
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
	mix_color = vec_add(data->scene->plane->color, &mix_color);
	limit_color(&mix_color);
	new_color = create_rgb(&mix_color);
	// free(&diffuse_light);
	// free(&mix_color);
	return (new_color);
}
int	cy_quadratic(t_data *data, t_cylinder *cy, float dist[2])
{
	float		radius;
	t_vector	x;
	t_vector	diff;
	t_vector	x_x_diff;
	t_vector	d_x_diff;
	t_vector	add;
	t_vector	mult;
	float		a;
	float		b;
	float		c;
	// (void)dist[2];


	x = vec_subtract(cy->ray, cy->center);
	mult = vec_multiplying(cy->direction, cy->height);
	// printf("mult = %f %f %f\n",mult.x,mult.y,mult.z);
	// printf("cy->direction = %f %f %f\n",cy->direction->x,cy->direction->y,cy->direction->z);
	add = vec_add(cy->center, &mult);
// printf("add = %f %f %f\n", add.x, add.y, add.z);
	diff = vec_subtract(cy->center, &add);
	// printf("cy.center = %f %f %f\n", cy->center->x, cy->center->y, cy->center->z);
	// printf("diff = %f %f %f\n", diff.x, diff.y, diff.z);
	x_x_diff = vec_cross(&x, &diff);
	// printf("x_x_diff = %f %f %f\n", x_x_diff.x, x_x_diff.y, x_x_diff.z);
	d_x_diff = vec_cross(cy->ray_dir, &diff);
	radius = vec_dot_product(&diff, &diff);
	// printf("radius = %f\n", radius);
	// t_vector	for_cross;
	// t_vector	for_sub;
	// t_vector	ray_cross;
	(void)data;
	a = vec_dot_product(&d_x_diff, &d_x_diff);
	// printf("a = %f\n", a);
	b = 2 * vec_dot_product(&d_x_diff, &x_x_diff);
	// printf("b = %f\n", b);
	c = vec_dot_product(&x_x_diff, &x_x_diff) - ((cy->diameter / 2) *
		(cy->diameter / 2) * radius);
	// printf("c = %f\n", c);
	float	discr;
	discr = (b * b) - (4 * a * c);
	// printf("discr = %f\n", discr);
	if (discr < 0)
		return (ERROR);
	discr = sqrtf(discr);
	if (dist[0] < dist[1])
			return (dist[0]);
	return (dist[1]);
}

// ************************************************************************** //
