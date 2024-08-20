/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:41:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/08/20 18:02:26 by mpelluet         ###   ########.fr       */
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

t_vector	*get_diffuse_light(t_data *data)
{
	t_vector	*norm;
	t_vector	*color;
	float		ratio;

	data->scene->spheres->impact_point = vec_add(data->scene->camera->origine,
		vec_multiplying(data->scene->spheres->ray,
		data->scene->spheres->dist_cam_sphere));
	norm = vec_subtract(data->scene->spheres->impact_point,
		data->scene->spheres->center);
	vec_normalize(norm);
	data->scene->spheres->ray_light = 
		vec_subtract(data->scene->spheres->impact_point,
		data->scene->light->origine);
	vec_normalize(data->scene->spheres->ray_light);
	ratio = vec_dot_product(norm, data->scene->spheres->ray_light);
	if (ratio < 0)
		color = NULL;
	else
		color = vec_multiplying(data->white_light, ratio);
	free(norm);
	return (color);
}

int	get_color_sphere(t_data *data)
{
	int			new_color;
	t_vector	*ambient_light; // a degager car a mettre dans la struc direct
	t_vector	*diffuse_light;
	t_vector	*mix_color;
	
	new_color = 0;
	data->scene->spheres->dist_cam_sphere = 
		sphere_intersect(data->scene->camera->origine,
			data->scene->spheres->ray, data->scene->spheres);
	if (data->scene->spheres->dist_cam_sphere > 0
		&& data->scene->spheres->dist_cam_sphere != EXIT_FAILURE)
	{
		ambient_light = vec_multiplying(data->scene->ambient->colors,
			data->scene->ambient->ratio);
		mix_color = ambient_light;
		diffuse_light = get_diffuse_light(data);
		if (diffuse_light)
			mix_color = vec_add(ambient_light, diffuse_light);
		mix_color = vec_add(data->scene->spheres->color, mix_color);
		mix_color->x = checking_limit(mix_color->x / 2., 0.0f, 255.0f);
		mix_color->y = checking_limit(mix_color->y / 2., 0.0f, 255.0f);
		mix_color->z = checking_limit(mix_color->z / 2., 0.0f, 255.0f);
		new_color = create_rgb(mix_color);
	}
	// free(ambient_light);
	// free(diffuse_light);
	// free(mix_color);
	return (new_color);
}
