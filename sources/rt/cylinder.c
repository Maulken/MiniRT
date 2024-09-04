/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/04 12:03:26 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	cylinder_intersect(t_data *data, t_cylinder *cy)
{
	float	b;
	float	c;
	float	dist[2];
	t_vector	*cy_cam;

	cy_cam = vec_subtract(data->scene->camera->origine, cy->center);
	b = 2 * vec_dot_product(cy->orientation, cy_cam);
	c = vec_dot_product(cy_cam, cy_cam)
		- ft_square(cy->diameter / 2);
	free(cy_cam);
	if (quadratic_equation(dist, 1, b, c) == EXIT_FAILURE)
		return (-1);
	if (dist[0] < dist[1])
		return (dist[0]);
	return (dist[1]);
}
float	on_cy(t_data *data, t_cylinder *cy)
{
	float	dist;
	float	height_pos;

	dist = vec_lenght(cy->impact_point, cy->center);
	height_pos = sqrt((cy->diameter / 2 * cy->diameter / 2) + (dist * dist));
	if (height_pos <= cy->height / 2)
		return (OK);
	return(0);
}

int	get_color_cylinder(t_data *data, t_cylinder *cy)
{
	int			new_color;
	t_vector	*diffuse_light;
	t_vector	*mix_color;

	new_color = 0;
	diffuse_light = NULL;
	mix_color = NULL;
	cy->dist_cam_cylinder = cylinder_intersect(data, cy);
	if (cy->dist_cam_cylinder >= 0)
	{
		cy->impact_point = vec_add(data->scene->camera->origine,
			vec_multiplying(cy->ray, cy->dist_cam_cylinder));
		if (on_cy(data, cy))
			new_color = get_mix_color(data);
		else
			add_plane(data, cy);
	}
	else
		add_plane(data, cy);
	return (new_color);
}

t_vector	*get_diffuse_light_cy(t_data *data)
{
	t_vector	*norm;
	t_vector	*color;
	float		ratio;

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

void	obtain_ray_cy(t_data *data, float x_ray, float y_ray)
{
	//t_vector	*for_ray;
	//for_ray = new_vector(x_ray, y_ray, data->scene->camera->orientation->z);
	data->scene->cylinder->ray= new_vector(x_ray, y_ray, 1.0);
	printf("ray: %f, %f, %f\n", x_ray, y_ray, 1.0);
	//data->scene->cylinder->ray = vec_subtract(for_ray,
	///		data->scene->camera->origine);
	vec_normalize(data->scene->cylinder->ray);
	//free(for_ray);
}
