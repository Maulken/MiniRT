/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/11 12:09:18 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	t_vector	up_y;

	up_y = new_vector(0, 1, 0);
	data->view->distance = 1. / (tanf((M_PI / 180.) *
		data->scene->camera->fov / 2.));
	// data->view->distance = 1
	// 	/ (2 * tanf(data->scene->camera->fov / 2));
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

	// printf("hit_dist %f\n", data->hit->distance);
	dist = plane_intersect(data, tmp.plane);
	// if (dist != -1)
		// printf("dist plane %f\n", dist);
	if (dist < data->hit->distance && dist > 0)
	{
		data->hit->distance = dist;
	// printf("hit dist = %f\n", data->hit->distance);
		data->hit->plane = tmp.plane;
		return (PLANE);
	}
	return (NONE);
}

int	is_cylinder(t_data *data, t_scene tmp)
{
	float	dist;

	dist = 0;
	dist = cylinder_intersect(data, tmp.cylinder);
	// if (dist != -1)
	// 	return (NONE);
		// printf("dist cy %f\n", dist);
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
	if (dist < data->hit->distance && dist > 0)
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
		// printf("center tmp %f %f %f\n", tmp.spheres->center->x, tmp.spheres->center->y, tmp.spheres->center->z);
		object = is_sphere(data, tmp);
		// printf("object sp %d\n", object);
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
		free(tmp.plane->ray);
		tmp.plane = tmp.plane->next;
	}
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


// void	init_tmp_ray(t_scene *tmp, t_object object)
// {
// 	if (tmp->spheres && object == SPHERE)
// 	{
// 		tmp->spheres->ray = ft_calloc(1, sizeof(t_vector));
// 		if (tmp->spheres->ray == NULL)
// 			error_allocation();
// 		return ;
// 	}
// 	else if (tmp->plane && object == PLANE)
// 	{
// 		tmp->plane->ray = ft_calloc(1, sizeof(t_vector));
// 		if (tmp->plane->ray == NULL)
// 			error_allocation();
// 		return ;
// 	}
// 	else if (tmp->cylinder && object == CYLINDER)
// 	{
// 		tmp->cylinder->ray = ft_calloc(1, sizeof(t_vector));
// 		if (tmp->cylinder->ray == NULL)
// 			error_allocation();
// 		return ;
// 	}
// }

// void	free_tmp(t_scene *tmp)
// {
// 	if (tmp->spheres->ray != NULL)
// 		free(tmp->spheres->ray);
// 	else if (tmp->plane->ray != NULL)
// 		free(tmp->plane->ray);
// 	else if (tmp->cylinder->ray != NULL)
// 		free(tmp->cylinder->ray);
// }

// static void	init_hit_sphere(t_hit *hit)
// {
// 	hit->sphere->ray = ft_calloc(1, sizeof(t_vector));
// 	if (hit->sphere->ray == NULL)
// 		error_allocation();
// 	hit->sphere->ray_light = ft_calloc(1, sizeof(t_vector));
// 	if (hit->sphere->ray_light == NULL)
// 		error_allocation();
// 	hit->sphere->impact_point = ft_calloc(1, sizeof(t_vector));
// 	if (hit->sphere->impact_point == NULL)
// 		error_allocation();
// 	hit->sphere->dist_cam_sphere = 0;
// 	hit->sphere->dist_light_sphere = 0;
// }

// static void	reinit_hit(t_hit *hit)
// {
// 	if (hit->sphere->ray != NULL)
// 		free(hit->sphere->ray);
// 	if (hit->sphere->ray_light != NULL)
// 		free(hit->sphere->ray_light);
// 	if (hit->sphere->impact_point != NULL)
// 		free(hit->sphere->impact_point);
// }

int	get_color(t_data *data, t_vector x_ray, t_vector y_ray)
{
	// printf("\e[35mGET_COLOR\e[0m\n");
	int		color;
	int		object;
	t_scene	tmp;

	// color = 0;
	color = 0x3300ff;
	tmp = *data->scene;
	// printf("diam %f\n", data->scene->spheres->diameter);
	// printf("center tmp %f %f %f\n", tmp.spheres->center->x, tmp.spheres->center->y, tmp.spheres->center->z);
	data->hit->distance = INFINITY;
	object = NONE;
	object = get_hit(data, tmp, x_ray, y_ray);
	if (object == SPHERE)
	{
		// if (data->hit->sphere->center->x != 0.)
			// printf("\e[35mcenter x hit\e[0m %f\n", data->hit->sphere->center->x);
		init_hit_sphere(data->hit);
		// printf("\e[32mSPHERE\e[0m\n");
		// printf("diam %f\n", data->hit->sphere->diameter);
		// *data->hit->sphere->ray = obtain_ray(data, x_ray, y_ray);
		color = get_color_sphere(data, data->hit);
		reinit_hit(data->hit);
	}
	if (object == PLANE)
	{
		init_hit_plane(data->hit);
		//printf("\e[32mPLANE\e[0m\n");
		// printf("diam %f\n", data->hit->sphere->diameter);
		// *data->hit->plane->ray = obtain_ray(data, x_ray, y_ray);
		color = get_color_plane(data);
		printf("color plan %d\n", color);
	}
	if (object == CYLINDER)
	{
		printf("object cy %d\n", object);
		init_hit_cylinder(data->hit);
		//printf("\e[32mCYLINDER\e[0m\n");
		// printf("diam %f\n", data->hit->cylinder->diameter);
		//*data->hit->cylinder->ray = obtain_ray(data, x_ray, y_ray);
		color = get_color_cylinder(data, data->hit);
	}
	//printf("before color\n");
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
		y = (2 * data->mlx_y / data->view->height - 1);
		y_ray = vec_multiplying(data->view->viewplane_y, y);
		data->mlx_x = 0;
		while (data->mlx_x < data->view->width)
		{
			x = -(2 * data->mlx_x / data->view->width - 1) *
				(data->view->width / data->view->height);
			x_ray = vec_multiplying(data->view->viewplane_x, x);
			my_mlx_pixel_put(data, get_color(data, x_ray, y_ray));
			data->mlx_x++;
		}
		data->mlx_y++;
	}
}
