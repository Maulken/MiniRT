/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 10:39:06 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	t_vector	up_y;

	up_y = new_vector(0, 1, 0);
	data->view->distance = 1. / (tanf(M_PI * data->scene->camera->fov / 360.));
	*data->view->viewplane_x = vec_cross(data->scene->camera->direction, &up_y);
	vec_normalize(data->view->viewplane_x);
	*data->view->viewplane_y = vec_cross(data->scene->camera->direction,
		data->view->viewplane_x);
	vec_normalize(data->view->viewplane_y);
}
// void	get_view_plane(t_data *data)
// {
// 	float	aspect_ratio;
// 	float	width;
// 	float	height;

// 	aspect_ratio = data->view->width / data->view->height;
// 	width = 2 * tan(data->scene->camera->fov / 2 * (M_PI / 180));
// 	height = width / aspect_ratio;
// 	data->view->x_pixel = width / data->view->width;
// 	data->view->y_pixel = height / data->view->height;
// }

int	is_plane(t_data *data, t_scene tmp)
{
	float	dist;

	dist = 0;
	dist = plane_intersect(data, tmp.plane);
	// if (dist != -1)
		// printf("dist plane %f\n", dist);
	if (dist < data->hit->distance && dist > 0)
	{
		data->hit->distance = dist;
	// printf("hit dist = %f\n", data->hit->distance);
		data->hit->plane = tmp.plane;
		init_hit_plane(data->hit);
		return (PLANE);
	}
	else if (data->hit->sphere != NULL)
	{
		//free qqch
		return (SPHERE);
	}
	return (NONE);
}

int	is_cylinder(t_data *data, t_scene tmp)
{
	float	dist;

	dist = 0;
	dist = cylinder_intersect(data, tmp.cylinder);
	if (dist == -1)
		return (NONE);
	// if(dist != 0)
	// 	printf("dist cy %f\n", dist);
	if (dist < data->hit->distance && dist > 0)
	{
		data->hit->distance = dist;
		data->hit->cylinder= tmp.cylinder;
		init_hit_cylinder(data->hit);
		return (CYLINDER);
	}
	return (NONE);
}

int	is_sphere(t_data *data, t_scene tmp)
{
	float	dist;

	dist = 0;
	dist = sphere_intersect(data->scene->camera->origine,
			tmp.spheres->ray, tmp.spheres);
	// if (dist != -1)
	// 	printf("dist %f\n", dist);
	// if (dist < data->hit->distance && dist > 1)
	if (dist < data->hit->distance && dist >= 0)
	{
		data->hit->distance = dist;
		data->hit->sphere = tmp.spheres;
		init_hit_sphere(data->hit);
		// printf("center x hit %f\n", data->hit->sphere->center->x);
		return (SPHERE);
	}
	else if (data->hit->sphere != NULL)
	{
		free(tmp.spheres->ray);
		free(tmp.spheres->ray_dir);
		return (SPHERE);
	}
	return (NONE);
}

t_vector	obtain_ray(t_data *data, t_vector x_ray, t_vector y_ray)
{
	t_vector	ray_without_z;
	t_vector	z;
	t_vector	result;

	ray_without_z = vec_add(&x_ray, &y_ray);
	// printf("view dist %f\n", data->view->distance);
	z = vec_multiplying(data->scene->camera->direction, data->view->distance);
	result = vec_add(&ray_without_z, &z);
	result = vec_add(&result, data->scene->camera->origine);
	// vec_normalize(&result);
	// printf("result %f %f %f\n", result.x, result.y, result.z);
	return (result);
}

int	get_hit(t_data *data, t_scene tmp, t_vector x_ray, t_vector y_ray)
{
	// printf("\e[35mGET_HIT\e[0m\n");
	int	object;

	object = NONE;
	while (tmp.spheres)
	{
		init_tmp_ray(&tmp, SPHERE);
		*tmp.spheres->ray = obtain_ray(data, x_ray, y_ray);
		*tmp.spheres->ray_dir = vec_subtract(tmp.spheres->ray, data->scene->camera->origine);
		vec_normalize(tmp.spheres->ray_dir);
		object = is_sphere(data, tmp);
		// free(tmp.spheres->ray);
		// free(tmp.spheres->ray_dir);
		tmp.spheres = tmp.spheres->next;
		// if (object == SPHERE && data->hit->sphere->center->x != 2.)
		// 	printf("\e[31mcenter x hit\e[0m %f\n", data->hit->sphere->center->x);
	}
	while (tmp.plane)
	{
		init_tmp_ray(&tmp, PLANE);
		*tmp.plane->ray = obtain_ray(data, x_ray, y_ray);
		*tmp.plane->ray_dir = vec_subtract(tmp.plane->ray, data->scene->camera->origine);
		vec_normalize(tmp.plane->ray_dir);
		// printf("center tmp %f %f %f\n", tmp.plane->center->x, tmp.plane->center->y, tmp.plane->center->z);
		object = is_plane(data, tmp);
		//  printf("object pl %d\n", object);
		// free(tmp.plane->ray);
		tmp.plane = tmp.plane->next;
	}
	// printf("szdfg\n");
	while (tmp.cylinder)
	{
		init_tmp_ray(&tmp, CYLINDER);
		*tmp.cylinder->ray = obtain_ray(data, x_ray, y_ray);
		*tmp.cylinder->ray_dir = vec_subtract(tmp.cylinder->ray, data->scene->camera->origine);
		vec_normalize(tmp.cylinder->ray_dir);
		// printf("center tmp %f %f %f\n", tmp.cylinder->center->x, tmp.cylinder->center->y, tmp.cylinder->center->z);
		object = is_cylinder(data, tmp);
		if (object == CYLINDER)
			printf("object cy %d\n", object);
		free(tmp.cylinder->ray);
		tmp.cylinder = tmp.cylinder->next;
	}
	return (object);
}

int	get_color(t_data *data, t_vector x_ray, t_vector y_ray)
{
	// printf("\e[35mGET_COLOR\e[0m\n");
	int		color;
	int		object;
	t_scene	tmp;

	// color = 0;
	color = 0x3300ff;
	tmp = *data->scene;
	data->hit->distance = INFINITY;
	object = NONE;
	object = get_hit(data, tmp, x_ray, y_ray);
	if (object == SPHERE)
	{
		init_hit_sphere(data->hit);
		color = get_color_sphere(data, data->hit);
		reinit_hit(data->hit);
	}
	if (object == PLANE)
	{
		init_hit_plane(data->hit);
		color = get_color_plane(data);
		reinit_hit(data->hit);
	}
	if (object == CYLINDER)
	{
		init_hit_cylinder(data->hit);
		// printf("color\n");
		color = get_color_cylinder(data, data->hit);
		reinit_hit(data->hit);
	}
	return (color);
}

void	ray_tracing(t_data *data)
{
	float	x;
	float	y;
	t_vector	x_ray;
	t_vector	y_ray;

	x_ray.z = 0;
	y_ray.z = 0;
	y = 0;
	x = 0;
	get_view_plane(data);
	data->mlx_y = 0;
	while (data->mlx_y < data->view->height)
	{
		y = (2 * data->mlx_y - data->view->height) / data->view->height;
		y_ray = vec_multiplying(data->view->viewplane_y, y);
		data->mlx_x = 0;
		while (data->mlx_x < data->view->width)
		{
			x = (2 * data->mlx_x - data->view->width) / data->view->width;
			x *= (float)data->view->width / (float)data->view->height;
			x_ray = vec_multiplying(data->view->viewplane_x, x);
			my_mlx_pixel_put(data, get_color(data, x_ray, y_ray));
			data->mlx_x++;
		}
		data->mlx_y++;
	}
}
