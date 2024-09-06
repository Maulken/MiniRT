/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/06 15:02:34 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	t_vector	up_y;

	up_y = new_vector(0,1,0);
	data->view->distance = 1
		/ (2 * tanf(data->scene->camera->fov / 2 * (M_PI / 180)));
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

int	is_plane(t_data *data, t_scene tmp, int object)
{
	tmp.plane->dist_cam_plane = plane_intersect(data, tmp.plane);
	if (tmp.plane->dist_cam_plane < data->hit->distance
		&& tmp.plane->dist_cam_plane != EXIT_FAILURE)
	{
		data->hit->plane = tmp.plane;
		data->hit->sphere = NULL;
		return (PLANE);
	}
	if (object != NONE)
		return (object);
	return (NONE);
}

int	is_cylinder(t_data *data, t_scene tmp, int object)
{
	tmp.cylinder->dist_cam_cylinder = cylinder_intersect(data, tmp.cylinder);
	if (tmp.cylinder->dist_cam_cylinder < data->hit->distance
		&& tmp.cylinder->dist_cam_cylinder != EXIT_FAILURE)
	{
		data->hit->cylinder = tmp.cylinder;
		data->hit->sphere = NULL;
		data->hit->plane = NULL;
		return (CYLINDER);
	}
	if (object != NONE)
		return (object);
	return (NONE);
}

int	is_sphere(t_data *data, t_scene tmp)
{
	float	dist;

	dist = 0;
	dist = sphere_intersect(data->scene->camera->origine,
			tmp.spheres->ray, tmp.spheres);
	if (dist != -1)
		printf("dist %f\n", dist);
	if (dist < data->hit->distance && dist > 1)
	{
		data->hit->distance = dist;
		data->hit->sphere = tmp.spheres;
		return (SPHERE);
	}
	return (NONE);
}

int	get_hit(t_data *data, t_scene tmp, t_vector x_ray, t_vector y_ray)
{
	// printf("\e[35mGET_HIT\e[0m\n");
	int	object;
	t_sphere	*next;

	object = NONE;
	while (tmp.spheres)
	{
		next = tmp.spheres->next;
		init_tmp_ray(&tmp, SPHERE);
		*tmp.spheres->ray = obtain_ray_sphere(data, x_ray, y_ray);
		// printf("center tmp %f %f %f\n", tmp.spheres->center->x, tmp.spheres->center->y, tmp.spheres->center->z);
		object = is_sphere(data, tmp);
		// printf("object %d\n", object);
		free(tmp.spheres->ray);
		tmp.spheres = next;
	}
	// while (tmp.plane)
	// {
	// 	obtain_ray_pl(data, FOR_HIT, tmp, x_ray, y_ray);
	// 	object = is_plane(data, tmp, object);
	// 	free(tmp.plane->ray);
	// 	tmp.plane = tmp.plane->next;
	// }
	// while (tmp.cylinder)
	// {
	// 	obtain_ray_cy(data, FOR_HIT, tmp, x_ray, y_ray);
	// 	object = is_cylinder(data, tmp, object);
	// 	free(tmp.cylinder->ray);
	// 	tmp.cylinder = tmp.cylinder->next;
	// }
	return (object);
}


void	init_tmp_ray(t_scene *tmp, t_object object)
{
	if (tmp->spheres && object == SPHERE)
	{
		tmp->spheres->ray = ft_calloc(1, sizeof(t_vector));
		if (tmp->spheres->ray == NULL)
			error_allocation();
		return ;
	}
	else if (tmp->plane && object == PLANE)
	{
		tmp->plane->ray = ft_calloc(1, sizeof(t_vector));
		if (tmp->plane->ray == NULL)
			error_allocation();
		return ;
	}
	else if (tmp->cylinder && object == CYLINDER)
	{
		tmp->cylinder->ray = ft_calloc(1, sizeof(t_vector));
		if (tmp->cylinder->ray == NULL)
			error_allocation();
		return ;
	}
}

void	free_tmp(t_scene *tmp)
{
	if (tmp->spheres->ray != NULL)
		free(tmp->spheres->ray);
	else if (tmp->plane->ray != NULL)
		free(tmp->plane->ray);
	else if (tmp->cylinder->ray != NULL)
		free(tmp->cylinder->ray);
}

static void	init_hit_sphere(t_hit *hit)
{
	hit->sphere->ray = ft_calloc(1, sizeof(t_vector));
	if (hit->sphere->ray == NULL)
		error_allocation();
	hit->sphere->ray_light = ft_calloc(1, sizeof(t_vector));
	if (hit->sphere->ray_light == NULL)
		error_allocation();
	hit->sphere->impact_point = ft_calloc(1, sizeof(t_vector));
	if (hit->sphere->impact_point == NULL)
		error_allocation();
	hit->sphere->dist_cam_sphere = 0;
	hit->sphere->dist_light_sphere = 0;
}

static void	reinit_hit(t_hit *hit)
{
	if (hit->sphere->ray != NULL)
		free(hit->sphere->ray);
	if (hit->sphere->ray_light != NULL)
		free(hit->sphere->ray_light);
	if (hit->sphere->impact_point != NULL)
		free(hit->sphere->impact_point);
}

int	get_color(t_data *data, t_vector x_ray, t_vector y_ray)
{
	// printf("\e[35mGET_COLOR\e[0m\n");
	int	color;
	int	object;
	t_scene	tmp;
	color = 0;
	// color = 0xff0000;
	tmp = *data->scene;
	data->hit->distance = INFINITY;
	object = NONE;
	object = get_hit(data, tmp, x_ray, y_ray);
	if (object == SPHERE)
	{
		// printf("center hit %f %f %f\n", data->hit->sphere->center->x, data->hit->sphere->center->y, data->hit->sphere->center->z);
		init_hit_sphere(data->hit);
		printf("\e[32mSPHERE\e[0m\n");
		// printf("diam %f\n", data->hit->sphere->diameter);
		*data->hit->sphere->ray = obtain_ray_sphere(data, x_ray, y_ray);
		color = get_color_sphere(data, data->hit);
	}
	// if (object == PLANE)
	// {
	// 	obtain_ray_pl(data,FOR_COLOR, tmp, x_ray, y_ray);
	// 	color = get_color_plane(data);
	// }
	// if (object == CYLINDER)
	// {
	// 	obtain_ray_cy(data,FOR_COLOR, tmp, x_ray, y_ray);
	// 	color = get_color_cylinder(data, data->scene->cylinder);
	// 	// printf("color %d\n", color);
	// }
	//printf("before color\n");
	//reinit_hit(data->hit);
	return (color);
}

void	ray_tracing(t_data *data)
{
	float	x_scale;
	float	y_scale;
	t_vector	x_ray;
	t_vector	y_ray;

	// x_ray.x = 0;
	// x_ray.y = 0;
	x_ray.z = 0;
	// y_ray.x = 0;
	// y_ray.y = 0;
	y_ray.z = 0;
	get_view_plane(data);
	data->mlx_y = 0;
	y_scale = (data->view->height / 2);
	while (y_scale >= (data->view->height / 2) * (-1))
	{
		y_ray = vec_multiplying(data->view->viewplane_y, y_scale);
		x_scale = (data->view->width / 2) * (-1);
		data->mlx_x = 0;
		while (x_scale <= data->view->width / 2)
		{
			x_ray = vec_multiplying(data->view->viewplane_x, x_scale);
			my_mlx_pixel_put(data, get_color(data, x_ray, y_ray));
			x_scale++;
			data->mlx_x++;
		}
		y_scale--;
		data->mlx_y++;
	}
}
