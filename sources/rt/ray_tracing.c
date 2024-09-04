/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/04 14:19:49 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	t_vector	up_y;

	up_y = new_vector(0,1,0);
	data->view->distance = 1
		/ (2 * tan(data->scene->camera->fov / 2 * (M_PI / 180)));
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

// int	is_plane(t_data *data, t_scene *tmp, int object)
// {
// 	tmp->plane->dist_cam_plane = plane_intersect(tmp->camera->origine,
// 			tmp->plane->ray, tmp->plane);
// 	if (tmp->plane->dist_cam_plane < data->hit->distance
// 		&& tmp->plane->dist_cam_plane != EXIT_FAILURE)
// 	{
// 		data->hit->plane = tmp->plane;
// 		data->hit->sphere = NULL;
// 		return (PLANE);
// 	}
// 	if (object != NONE)
// 		return (object);
// 	return (NONE);
// }

// int	is_cylinder(t_data *data, t_scene *tmp, int object)
// {
// 	tmp->cylinder->dist_cam_cylinder = plane_intersect(tmp->camera->origine,
// 			tmp->cylinder->ray, tmp->cylinder);
// 	if (tmp->cylinder->dist_cam_cylinder < data->hit->distance
// 		&& tmp->cylinder->dist_cam_cylinder != EXIT_FAILURE)
// 	{
// 		data->hit->cylinder = tmp->cylinder;
// 		data->hit->sphere = NULL;
// 		data->hit->plane = NULL;
// 		return (CYLINDER);
// 	}
// 	if (object != NONE)
// 		return (object);
// 	return (NONE);
// }

int	is_sphere(t_data *data, t_scene tmp)
{
	float	dist;
	
	dist = 0;
	dist = sphere_intersect(data->scene->camera->origine,
			tmp.spheres->ray, tmp.spheres);
	// printf("dist %f\n", dist);
	if (dist < data->hit->distance && dist > 0)
	{
		data->hit->distance = dist;
		data->hit->sphere = tmp.spheres;
		return (SPHERE);
	}
	return (NONE);
}

int	get_hit(t_data *data, t_scene tmp, t_vector x_ray, t_vector y_ray)
// int	get_hit(t_data *data, t_scene tmp, float x_ray, float y_ray)
{
	int	object;
	
	object = NONE;
	while (tmp.spheres)
	{
		obtain_ray_sphere(data, FOR_HIT, tmp, x_ray, y_ray);
		object = is_sphere(data, tmp);
		free(tmp.spheres->ray);
		tmp.spheres->ray = NULL;
		// free_inside_sphere(tmp.spheres);
		tmp.spheres = tmp.spheres->next;
	}
	// while (tmp->plane)
	// {
	// 	obtain_ray_plane(data, PLANE, x_ray, y_ray);
	// 	object = is_plane(data, tmp, object);
	// 	tmp->plane = tmp->plane->next;
	// }
	// while (tmp->cylinder)
	// {
	// 	obtain_ray_cylinder(data, CYLINDER, x_ray, y_ray);
	// 	object = is_cylinder(data, tmp, object);
	// 	tmp->cylinder = tmp->cylinder->next;
	// }
	return (object);
}

void	reinit_hit(t_hit *hit)
{
	if (hit->sphere != NULL)
		hit->sphere = NULL;
	if (hit->plane != NULL)
		hit->plane = NULL;
	if (hit->cylinder != NULL)
		hit->cylinder = NULL;
}

int	get_color(t_data *data, t_vector x_ray, t_vector y_ray)
// int	get_color(t_data *data, float x_ray, float y_ray)
{
	int	color;
	int	object;
	t_scene	tmp;
	
	color = 0;
	// color = 0xff0000;
	tmp = *data->scene;
	// data->hit->distance = INFINITY;
	data->hit->distance = 100.0;
	object = NONE;
	object = get_hit(data, tmp, x_ray, y_ray); 
	if (object == SPHERE)
	{
		obtain_ray_sphere(data, FOR_COLOR, tmp, x_ray, y_ray);
		color = get_color_sphere(data, data->hit);
		// printf("color %d\n", color);
	}
	// if (object == PLANE)
	// 	color = get_color_plane(data->hit);
	// if (object == CYLINDER)
	// 	color = get_color_cylinder(data->hit);
	// printf("before color\n");
	reinit_hit(data->hit);
	return (color);
}

void	ray_tracing(t_data *data)
{
	float	x_scale;
	float	y_scale;
	// float	x_ray;
	// float	y_ray;
	t_vector	x_ray;
	t_vector	y_ray;
	
	x_ray.x = 0;
	x_ray.y = 0;
	x_ray.z = 0;
	y_ray.x = 0;
	y_ray.y = 0;
	y_ray.z = 0;
	get_view_plane(data);
	data->mlx_y = 0;
	y_scale = (data->view->height / 2);
	while (y_scale >= (data->view->height / 2) * (-1))
	{
		// y_ray = y_scale * data->view->y_pixel;
		y_ray = vec_multiplying(data->view->viewplane_y, y_scale);
		x_scale = (data->view->width / 2) * (-1);
		data->mlx_x = 0;
		while (x_scale <= data->view->width / 2)
		{
			// x_ray = x_scale * data->view->x_pixel;
			x_ray = vec_multiplying(data->view->viewplane_x, x_scale);
			// my_mlx_pixel_put(data, get_color(data, x_ray, y_ray));
			my_mlx_pixel_put(data, get_color(data, x_ray, y_ray)); //avec t_vec pour x_ray et y_ray
			x_scale++;
			data->mlx_x++;
		}
		y_scale--;
		data->mlx_y++;
	}
}
