/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/21 19:40:09 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	float	aspect_ratio;
	float	width;
	float	height;

	aspect_ratio = data->view->width / data->view->height;
	width = 2 * tan(data->scene->camera->fov / 2 * (M_PI / 180));
	height = width / aspect_ratio;
	data->view->x_pixel = width / data->view->width;
	data->view->y_pixel = height / data->view->height;
}

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
	// printf("hit dist %f\n", data->hit->distance);
	// if (dist < data->hit->distance && dist != EXIT_FAILURE)
		// printf("adress %p\n", tmp);
	if (dist < data->hit->distance && dist > 0)
	{
		// printf("euh\n");
		data->hit->distance = dist;
		data->hit->sphere = tmp.spheres;
		// printf("normalement pas \n");
		return (SPHERE);
	}
	return (NONE);
}

int	get_hit(t_data *data, t_scene tmp, float x_ray, float y_ray)
{
	int	object;
	
	// printf("dans get_it\n");
	// object = NONE;
	object = PLANE;
	// printf("obejct avan boucle while dans get hit %d\n", object);
	// while (tmp->spheres)
	// printf("tmp %")
	while (tmp.spheres)
	{
		// printf("la\n");
		obtain_ray_sphere(data, FOR_HIT, tmp, x_ray, y_ray);
		object = is_sphere(data, tmp); 
		// printf("object %d\n", object);
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

int	get_color(t_data *data, float x_ray, float y_ray)
{
	int	color;
	int	object;
	t_scene	tmp;
	
	color = 0;
	// color = 0xff0000;
	// tmp = ft_calloc(1, sizeof(t_scene));
	tmp = *data->scene;
	data->hit->distance = INFINITY;
	// printf("diametre sph tmp %f\n", tmp.spheres->diameter);
	object = NONE;
	object = get_hit(data, tmp, x_ray, y_ray);
	// printf("avant if sphere\n");
	if (object == SPHERE)
	{
		// printf("\e[31mKHERGEAHGRUIHAEUGAEIRGH\e[0m\n");
		obtain_ray_sphere(data, FOR_COLOR, tmp, x_ray, y_ray);
		color = get_color_sphere(data, data->hit, tmp);
		printf("color %d\n", color);
	}
	// if (object == PLANE)
	// 	color = get_color_plane(data->hit);
	// if (object == CYLINDER)
	// 	color = get_color_cylinder(data->hit);
	// free(tmp);
	// tmp = NULL;
	// printf("before color\n");
	return (color);
}

void	ray_tracing(void *mlx, void *window, t_data *data)
{
	float		x_scale;
	float		y_scale;
	float		x_ray;
	float		y_ray;
	get_view_plane(data);
	data->mlx_y = 0;
	y_scale = (data->view->height / 2);
	while (y_scale >= (data->view->height / 2) * (-1))
	{
		y_ray = y_scale * data->view->y_pixel;
		x_scale = (data->view->width / 2) * (-1);
		data->mlx_x = 0;
		// printf("xRay %f, y_ray %f\n", x_ray, y_ray);
		while (x_scale <= data->view->width / 2)
		{
			x_ray = x_scale * data->view->x_pixel;
			my_mlx_pixel_put(data, get_color(data, -x_ray, -y_ray));
			x_scale++;
			data->mlx_x++;
		}
		y_scale--;
		data->mlx_y++;
	}
}
