/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/09 14:26:57 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	cylinder_intersect(t_data *data, t_cylinder *cy)
{
	// float	a;
	// float	b;
	// float	c;
	float	dist[2];
	// t_vector	*cross;
	// t_vector	*cy_cam;
	int		quadra;

	quadra = cy_quadratic(data, cy, dist);

	// cy_cam = vec_subtract(data->scene->camera->origine, cy->center);
	// // printf("cy_cam x %f , y %f, z %f \n", cy_cam->x, cy_cam->y, cy_cam->z);
	// cross = vec_cross(cy->ray, cy->direction);
	//  printf("cy_cam x %f , y %f, z %f \n", cross->x, cross->y, cross->z);
	// a = ft_square(vec_lenght(cross, cross));
	// // printf("a = %f\n", a);
	// b = 2 * vec_dot_product(cy->direction, cy_cam);

	// c = vec_dot_product(cy_cam, cy_cam) - ft_square(cy->diameter / 2);
	// free(cy_cam);
	if (quadra == EXIT_FAILURE)
		return (-1);
	// printf("dist[0] = %f dist[1] = %f\n", dist[0], dist[1]);
	if (dist[0] < dist[1])
		return (dist[0]);
	return (dist[1]);
}
float	on_cy(t_cylinder *cy)
{
	float	dist;
	float	height_pos;

	dist = vec_lenght(cy->impact_point, cy->center);
	printf("dist = %f\n", dist);
	height_pos = sqrt((dist * dist) - (cy->diameter / 2 * cy->diameter / 2));
	printf("pos = %f\n", height_pos);
	printf("long = %f\n", cy->height);
	if (height_pos <= cy->height / 2)
	{
		return (1);
	}
	return(0);
}

int	get_color_cylinder(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	for_impact;

	new_color = 0;
	hit->cylinder->dist_cam_cylinder = cylinder_intersect(data, hit->cylinder);
	// printf("dist = %f\n", cy->dist_cam_cylinder);
	if (hit->cylinder->dist_cam_cylinder >= 0)
	{
		printf("test\n");
		for_impact = vec_multiplying(hit->cylinder->ray,
			hit->cylinder->dist_cam_cylinder);
		*hit->cylinder->impact_point = vec_add(data->scene->camera->origine,
			&for_impact);
		if (on_cy(hit->cylinder))
			new_color = get_mix_color(data);
		// else
		// 	add_plane(data, hit->cylinder);
	}
	// else
	// 	add_plane(data, cy);
	printf("new_color = %d\n", new_color);
	return (new_color);
}

t_vector	get_diffuse_light_cy(t_data *data)
{
	t_vector	norm;
	t_vector	color;
	float		ratio;

	norm = vec_subtract(data->scene->cylinder->impact_point,
			data->scene->cylinder->center);
	vec_normalize(&norm);
	*data->scene->cylinder->ray_light =
			vec_subtract(data->scene->cylinder->impact_point,
			data->scene->light->origine);
	vec_normalize(data->scene->cylinder->ray_light);
	ratio = vec_dot_product(&norm, data->scene->cylinder->ray_light);
	printf("ratio = %f\n", ratio);
	// if (ratio < 0)
	// 	color = NULL;
	// else
	// 	*color = vec_multiplying(data->white_light, ratio);
	if (ratio >= 0)
		color = vec_multiplying(data->white_light, ratio);
	//free(&norm);
	return (color);
}

void	obtain_ray_cy(t_data *data, t_ray type_ray, t_scene tmp,
				float x_ray, float y_ray)
{
	(void)type_ray;
	(void)tmp;
	//t_vector	*for_ray;
	//for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
	*data->scene->cylinder->ray= new_vector(x_ray, y_ray, 1.0);
	//printf("ray: %f, %f, %f\n", x_ray, y_ray, 1.0);
	//data->scene->cylinder->ray = vec_subtract(for_ray,
	///		data->scene->camera->origine);
	vec_normalize(data->scene->cylinder->ray);
	//free(for_ray);
}
