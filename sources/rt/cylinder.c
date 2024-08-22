/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/22 16:16:47 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	cylinder_intersect(t_data *data, t_plane *pl)
{
	// float		dist;
	// float		num;
	// float		den;
	// t_vector	*pl_cam;

	// pl_cam = vec_subtract(data->scene->camera->origine, pl->origine);
	// //vec_normalize(pl_cam);
	// num = vec_dot_product(pl_cam, pl->orientation);
	// //printf("num = %f\n", num);
	// den = vec_dot_product(pl->ray, pl->orientation);
	// 	//printf("den = %f\n", den);
	// if (den != 0.0)
	// {
	// 	dist = num / den;
	// 	return(dist);
	// }
	return (-1);
}

int	get_color_cylinder(t_data *data)
{
	int			new_color;
	t_vector	*diffuse_light;
	t_vector	*mix_color;

	new_color = 0;
	diffuse_light = NULL;
	mix_color = NULL;
	data->scene->cylinder->dist_cam_cylinder =
		cylinder_intersect(data, data->scene->cylinder);
	if (data->scene->cylinder->dist_cam_cylinder >= 0)
	{
		mix_color = data->scene->ambient->ambient_light;
		diffuse_light = get_diffuse_light_pl(data);
		if (diffuse_light)
			mix_color = vec_add(data->scene->ambient->ambient_light,
			diffuse_light);
		mix_color = vec_add(data->scene->cylinder->color, mix_color);
		mix_color->x = checking_limit(mix_color->x / 2., 0.0f, 255.0f);
		mix_color->y = checking_limit(mix_color->y / 2., 0.0f, 255.0f);
		mix_color->z = checking_limit(mix_color->z / 2., 0.0f, 255.0f);
		new_color = create_rgb(mix_color);
	}
	free(diffuse_light);
	free(mix_color);
	return (new_color);
}

t_vector	*get_diffuse_light_cy(t_data *data)
{
	t_vector	*norm;
	t_vector	*color;
	float		ratio;

	data->scene->cylinder->impact_point = vec_add(data->scene->camera->origine,
			vec_multiplying(data->scene->cylinder->ray,
			data->scene->cylinder->dist_cam_cylinder));
	norm = vec_subtract(data->scene->cylinder->impact_point,
			data->scene->cylinder->center);
	vec_normalize(norm);
	data->scene->cylinder->ray_light =
		vec_subtract(data->scene->cylinder->impact_point,
		data->scene->light->origine);
	vec_normalize(data->scene->cylinder->ray_light);
	ratio = vec_dot_product(norm, data->scene->cylinder->ray_light);
	printf("ratio = %f\n", ratio);
	if (ratio < 0)
		color = NULL;
	else
		color = vec_multiplying(data->white_light, ratio);
	free(norm);
	return (color);
}

void	obtain_ray_pl(t_data *data, float x_ray, float y_ray)
{
	//t_vector	*for_ray;
	//for_ray = new_vector(x_ray, y_ray, data->scene->camera->orientation->z);
	data->scene->plane->ray= new_vector(x_ray, y_ray, 1.0);
	printf("ray: %f, %f, %f\n", x_ray, y_ray, 1.0);
	//data->scene->plane->ray = vec_subtract(for_ray,
	///		data->scene->camera->origine);
	vec_normalize(data->scene->plane->ray);
	//free(for_ray);
}


