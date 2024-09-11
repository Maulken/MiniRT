/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:08:39 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/11 11:57:09 by vmassoli         ###   ########.fr       */
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
	(void)dist[2];


	x = vec_subtract(cy->ray, cy->center);
	mult = vec_multiplying(cy->direction, cy->height);
	add = vec_add(cy->center, &mult);
	diff = vec_subtract(cy->center, &add);
	x_x_diff = vec_cross(&x, &diff);
	d_x_diff = vec_cross(cy->ray_dir, &diff);
	radius = vec_dot_product(&diff, &diff);
	// t_vector	for_cross;
	// t_vector	for_sub;
	// t_vector	ray_cross;
	(void)data;
	a = vec_dot_product(&d_x_diff, &d_x_diff);
	b = 2 * vec_dot_product(&d_x_diff, &x_x_diff);
	c = vec_dot_product(&x_x_diff, &x_x_diff) - ((cy->diameter / 2) *
		(cy->diameter / 2) * radius);
	float	discr;

	discr = (b * b) - (4 * a * c);
	// printf("discr = %f\n", discr);
	if (discr < 0)
		return (ERROR);
	// //printf("cy->ray_dir x = %f, y = %f, z = %f\n", cy->ray_dir->x, cy->ray_dir->y, cy->ray_dir->z);
	// for_cross = vec_cross(cy->ray_dir, cy->direction);
	// // // for_sub = vec_subtract(data->scene->camera->origine, cy->center);
	// //printf("for_cross x = %f, y = %f, z = %f\n", for_cross.x, for_cross.y, for_cross.z);
	// for_sub = vec_subtract(cy->ray, cy->center);
	// ray_cross = vec_cross(&for_sub, cy->direction);
	// // printf("ray_cross x = %f, y = %f, z = %f\n", ray_cross.x, ray_cross.y, ray_cross.z);
	// // // a = ft_square(vec_lenght(&for_cross, &for_cross));
	// a = vec_dot_product(&for_cross, &for_cross);
	// // printf("a = %f\n", a);
	// b = 2 * vec_dot_product(&for_cross, &ray_cross);
	// // printf("b = %f\n", b);
	// // // c = ft_square(vec_lenght(&ray_cross, &ray_cross)) - (cy->diameter / 2) *
	// // // 	(1 - ft_square(vec_dot_product(cy->ray, cy->direction)));
	// c = vec_dot_product(&ray_cross, &ray_cross) - (cy->diameter / 2) *
	// 	(cy->diameter / 2) * 1 - vec_dot_product(cy->ray_dir, cy->direction) *
	// 	 vec_dot_product(cy->ray_dir, cy->direction);
	// // printf("c = %f\n", c);
	return(discr);
}

// ************************************************************************** //

// static void	_cylinder_hit_compute(
// 				t_object_cylinder *cylinder,
// 				const t_ray *ray,
// 				t_cylinder_vars *vars
// 				)
// {
	// t_vector3	x;
	// t_vector3	diff;
	// t_vector3	x_x_diff;
	// t_vector3	d_x_diff;
// 	t_coord		radius;

// 	vec3_sub(&x, &ray->origin, &cylinder->origin);
// 	vec3_sub(&diff, &cylinder->origin,
// 		vec3_add(&diff, &cylinder->origin,
// 			vec3_mul(&diff, &cylinder->axis, cylinder->height)));
// 	vec3_cross(&x_x_diff, &x, &diff);
// 	vec3_cross(&d_x_diff, &ray->dir, &diff);
// 	radius = vec3_dot(&diff, &diff);
// 	vars->a = vec3_dot(&d_x_diff, &d_x_diff);
// 	vars->b = 2 * vec3_dot(&d_x_diff, &x_x_diff);
// 	vars->c = vec3_dot(&x_x_diff, &x_x_diff)
// 		- ((cylinder->diameter / 2.) * (cylinder->diameter / 2.) * radius);
// 	vars->d = vars->b * vars->b - 4 * vars->a * vars->c;
// 	vars->d_sqrt = sqrt(vars->d);
// }
