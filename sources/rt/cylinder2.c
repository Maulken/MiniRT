/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:08:39 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/09 15:07:07 by vmassoli         ###   ########.fr       */
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
	t_vector	for_cross;
	t_vector	for_sub;
	t_vector	ray_cross;
	float		a;
	float		b;
	float		c;
	(void)data;

	for_cross = vec_cross(cy->ray, cy->direction);
	// for_sub = vec_subtract(data->scene->camera->origine, cy->center);
	for_sub = vec_subtract(cy->direction, cy->center);
	ray_cross = vec_cross(&for_sub, cy->direction);
	// printf("ray_cross x = %f, y = %f, z = %f\n", ray_cross->x, ray_cross->y, ray_cross->z);
	// a = ft_square(vec_lenght(&for_cross, &for_cross));
	a = vec_dot_product(&for_cross, &for_cross);
	// printf("a = %f\n", a);
	b = 2 * vec_dot_product(&for_cross, &ray_cross);
	// printf("b = %f\n", b);
	// c = ft_square(vec_lenght(&ray_cross, &ray_cross)) - (cy->diameter / 2) *
	// 	(1 - ft_square(vec_dot_product(cy->ray, cy->direction)));
	c = vec_dot_product(&ray_cross, &ray_cross) - (cy->diameter / 2);
	// printf("c = %f\n", c);
	return(quadratic_equation(dist, a, b, c));
}
