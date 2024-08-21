/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:41:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/08/21 15:06:30 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	sphere_intersect(t_vector *origin, t_vector *direction, t_sphere *sph)
{
	float	b;
	float	c;
	float	dist[2];
	t_vector	*origine_sphere;
	
	origine_sphere = vec_subtract(origin, sph->center);
	b = 2 * vec_dot_product(direction, origine_sphere);
	c = vec_dot_product(origine_sphere, origine_sphere)
		- ft_square(sph->diameter / 2);
	free(origine_sphere);
	if (quadratic_equation(dist, 1, b, c))
		return (EXIT_FAILURE);
	if (dist[0] < dist[1])
		return (dist[0]);
	return (dist[1]);
}

t_vector	*get_diffuse_light(t_data *data, t_hit *hit)
{
	t_vector	*norm;
	t_vector	*color;
	float		ratio;

	hit->sphere->impact_point = vec_add(data->scene->camera->origine,
		vec_multiplying(hit->sphere->ray, hit->sphere->dist_cam_sphere));
	norm = vec_subtract(hit->sphere->impact_point, hit->sphere->center);
	vec_normalize(norm);
	hit->sphere->ray_light = vec_subtract(hit->sphere->impact_point,
		data->scene->light->origine);
	vec_normalize(hit->sphere->ray_light);
	ratio = vec_dot_product(norm, hit->sphere->ray_light);
	if (ratio < 0)
		color = NULL;
	else
		color = vec_multiplying(data->white_light, ratio);
	free(norm);
	return (color);
}

int	get_color_sphere(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	*diffuse_light;
	t_vector	*mix_color;
	
	new_color = 0;
	diffuse_light = NULL;
	mix_color = NULL;
	hit->sphere->dist_cam_sphere
		= sphere_intersect(data->scene->camera->origine,
			hit->sphere->ray, hit->sphere);
	if (hit->sphere->dist_cam_sphere > 0
		&& hit->sphere->dist_cam_sphere != EXIT_FAILURE)
	{
		mix_color = data->scene->ambient->ambient_light;
		diffuse_light = get_diffuse_light(data, hit);
		if (diffuse_light)
			mix_color = vec_add(data->scene->ambient->ambient_light,
				diffuse_light);
		mix_color = vec_add(hit->sphere->color, mix_color);
		limit_color(mix_color);
		new_color = create_rgb(mix_color);
	}
	free(diffuse_light);
	free(mix_color);
	return (new_color);
}

void	obtain_ray_sphere(t_data *data, float x_ray, float y_ray)
{
	t_vector	*for_ray;
	for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
	data->scene->spheres->ray = vec_subtract(for_ray,
			data->scene->camera->origine);
	vec_normalize(data->scene->spheres->ray);
	free(for_ray);
	for_ray = NULL;
}

// int	is_sphere(t_data *data, t_scene *tmp)
// {
// 	tmp->spheres->dist_cam_sphere = sphere_intersect(tmp->camera->origine,
// 			tmp->spheres->ray, tmp->spheres);
// 	if (tmp->spheres->dist_cam_sphere < data->hit->distance
// 		&& tmp->spheres->dist_cam_sphere != EXIT_FAILURE)
// 	{
// 		data->hit->sphere = tmp->spheres;
// 		return (SPHERE);
// 	}
// 	return (NONE);
// }
