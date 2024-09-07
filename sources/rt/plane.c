/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:11:07 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/06 15:33:08 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// float	plane_intersect(t_data *data, t_plane *pl)
// {
// 	float		dist;
// 	float		num;
// 	float		den;
// 	t_vector	*pl_cam;

// 	pl_cam = vec_subtract(data->scene->camera->origine, pl->origine);
// 	//vec_normalize(pl_cam);
// 	num = vec_dot_product(pl_cam, pl->direction);
// 	//printf("num = %f\n", num);
// 	den = vec_dot_product(pl->ray, pl->direction);
// 		//printf("den = %f\n", den);
// 	if (den != 0.0)
// 	{
// 		dist = num / den;
// 		return(dist);
// 	}
// 	return (-1);
// }

// int	get_color_plane(t_data *data)
// {
// 	int			new_color;
// 	t_vector	*diffuse_light;
// 	t_vector	*mix_color;

// 	new_color = 0;
// 	diffuse_light = NULL;
// 	mix_color = NULL;
// 	data->scene->plane->dist_cam_plane =
// 		plane_intersect(data, data->scene->plane);
// 	if (data->scene->plane->dist_cam_plane >= 0)
// 	{
// 		mix_color = data->scene->ambient->ambient_light;
// 		diffuse_light = get_diffuse_light_pl(data);
// 		if (diffuse_light)
// 			mix_color = vec_add(data->scene->ambient->ambient_light,
// 			diffuse_light);
// 		mix_color = vec_add(data->scene->plane->color, mix_color);
// 		limit_color(mix_color);
// 		new_color = create_rgb(mix_color);
// 	}
// 	free(diffuse_light);
// 	free(mix_color);
// 	return (new_color);
// }

// t_vector	*get_diffuse_light_pl(t_data *data)
// {
// 	t_vector	*norm;
// 	t_vector	*color;
// 	float		ratio;

// 	data->scene->plane->impact_point = vec_add(data->scene->camera->origine,
// 			vec_multiplying(data->scene->plane->ray,
// 			data->scene->plane->dist_cam_plane));
// 	norm = vec_subtract(data->scene->plane->impact_point,
// 			data->scene->plane->origine);
// 	vec_normalize(norm);
// 	data->scene->plane->ray_light =
// 		vec_subtract(data->scene->plane->impact_point,
// 		data->scene->light->origine);
// 	vec_normalize(data->scene->plane->ray_light);
// 	ratio = vec_dot_product(norm, data->scene->plane->ray_light);
// 	//printf("ratio = %f\n", ratio);
// 	if (ratio < 0)
// 		color = NULL;
// 	else
// 		color = vec_multiplying(data->white_light, ratio);
// 	free(norm);
// 	return (color);
// }

// void	obtain_ray_pl(t_data *data, t_ray type_ray, t_scene tmp,
// 				float x_ray, float y_ray)
// {
// 	// t_vector	*for_ray;
// 	(void)type_ray;
// 	(void)tmp;
// 	// for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
// 	data->scene->plane->ray= new_vector(x_ray, y_ray, 1.0);
// 	// printf("ray: %f, %f, %f\n", x_ray, y_ray, 1.0);
// 	//data->scene->plane->ray = vec_subtract(for_ray,
// 	///		data->scene->camera->origine);
// 	vec_normalize(data->scene->plane->ray);
// 	//free(for_ray);
// }


