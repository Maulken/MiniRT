/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:11:07 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/09 18:25:03 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	plane_intersect(t_data *data, t_plane *pl)
{
	// float		dist;
	// float		num;
	// float		den;
	// t_vector	pl_cam;
	// (void)data;

	// // pl_cam = vec_subtract(data->scene->camera->origine, pl->origine);
	// pl_cam = vec_subtract(pl->direction, pl->origine);
	// vec_normalize(&pl_cam);
	// // printf("pl_cam: %f, %f, %f\n", pl_cam.x, pl_cam.y, pl_cam.z);
	// num = vec_dot_product(&pl_cam, pl->direction);
	// // printf("direction: %f, %f, %f\n", pl->direction->x, pl->direction->y, pl->direction->z);
	// // printf("num = %f\n", num);
	// den = vec_dot_product(pl->ray, pl->direction);
	// 	printf("den = %f\n", den);
	// if (den != 0.0)
	// {
	// 	dist = num / den;
	// 	return(dist);
	// }
	// return (-1);

	(void)data;
	float d = vec_dot_product(pl->direction, pl->ray_dir);
	if (d <= 0)
		return (-1);
	t_vector	v = vec_subtract(pl->origine, pl->ray);
	d = vec_dot_product(&v, pl->direction) / d;
	printf("%f\n", d);
	return (d);
}

int	get_color_plane(t_data *data)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	new_color = 0;
	// diffuse_light = NULL;
	// mix_color = NULL;
	data->scene->plane->dist_cam_plane =
		plane_intersect(data, data->scene->plane);
	if (data->scene->plane->dist_cam_plane >= 0)
	{
		mix_color = *data->scene->ambient->ambient_light;
		diffuse_light = get_diffuse_light_pl(data);
		if (diffuse_light.x)
			mix_color = vec_add(data->scene->ambient->ambient_light,
			&diffuse_light);
		mix_color = vec_add(data->scene->plane->color, &mix_color);
		limit_color(&mix_color);
		new_color = create_rgb(&mix_color);
	printf("new color plan %d\n", new_color);
	}
	// free(diffuse_light);
	// free(mix_color);
	return (new_color);
}

t_vector	get_diffuse_light_pl(t_data *data)
{
	t_vector	norm;
	t_vector	for_impact;
	t_vector	color;
	float		ratio;

	for_impact = vec_multiplying(data->scene->plane->ray,
			data->scene->plane->dist_cam_plane);
	*data->scene->plane->impact_point = vec_add(data->scene->camera->origine,
			&for_impact);
	norm = vec_subtract(data->scene->plane->impact_point,
			data->scene->plane->origine);
	vec_normalize(&norm);
	*data->scene->plane->ray_light =
		vec_subtract(data->scene->plane->impact_point,
		data->scene->light->origine);
	vec_normalize(data->scene->plane->ray_light);
	ratio = vec_dot_product(&norm, data->scene->plane->ray_light);
	if (ratio >= 0)
		color = vec_multiplying(data->white_light, ratio);
	// printf("ratio = %f\n", ratio);
	// printf("color = %f\n", color.x);
	// if (ratio < 0)
	// 	color = NULL;
	// else
	// 	*color = vec_multiplying(data->white_light, ratio);
	// free(&norm);
	return (color);
}

// void	obtain_ray_plane(t_data *data, t_ray type_ray, t_scene tmp,
// 				float x_ray, float y_ray)
// {
// 	// t_vector	*for_ray;
// 	(void)type_ray;
// 	(void)tmp;
// 	// for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
// 	*data->scene->plane->ray= new_vector(x_ray, y_ray, 1.0);
// 	// printf("ray: %f, %f, %f\n", x_ray, y_ray, 1.0);
// 	//data->scene->plane->ray = vec_subtract(for_ray,
// 	///		data->scene->camera->origine);
// 	vec_normalize(data->scene->plane->ray);
// 	//free(for_ray);
// }

// t_vector	obtain_ray(t_data *data, t_vector x_ray, t_vector y_ray)
// {
// 	t_vector	ray_without_z;
// 	t_vector	z;
// 	t_vector	result;

// 	ray_without_z = vec_add(&x_ray, &y_ray);
// 	// printf("view dist %f\n", data->view->distance);
// 	z = vec_multiplying(data->scene->camera->direction, data->view->distance);
// 	result = vec_add(&ray_without_z, &z);
// 	vec_normalize(&result);
// 	// printf("result %f %f %f\n", result.x, result.y, result.z);
// 	return (result);
// }
