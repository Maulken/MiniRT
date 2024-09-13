/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:00:44 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:24:04 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	cylinder_intersect(t_data *data, t_cylinder *cy)
{
	float	dist_quadra[2];
	int		dist;
	float	on_cylinder;

	dist = cy_quadratic(data, cy, dist_quadra);
	if (dist == ERROR)
		return (-1);
	cy->dist_cam_cylinder = dist;
	on_cylinder = on_cy(cy);
	if (on_cylinder == 0)
		return(-1);
	return (dist);
}
float	on_cy(t_cylinder *cy)
{
	float	dist;
	float	height_pos;
	float	pyth;
	t_vector	for_impact;

	for_impact = vec_multiplying(cy->ray_dir, cy->dist_cam_cylinder);
	*cy->impact_point = vec_add(cy->ray, &for_impact);
	dist = vec_lenght(cy->impact_point, cy->center);
	if (dist < 0)
		return (0);
	pyth = (dist * dist) - ((cy->diameter / 2) * (cy->diameter / 2));
	if (pyth < 0)
		return(0);
	height_pos = sqrt(pyth);
	if (height_pos <= cy->height / 2)
		return (1);
	return(0);
}

int	get_color_cylinder(t_data *data, t_hit *hit)
{
	int	new_color;

	new_color = 0;
	if (hit->cylinder->dist_cam_cylinder >= 0)
		new_color = get_mix_color(data);
	return (new_color);
}

t_vector	get_diffuse_light_cy(t_data *data)
{
	t_vector	norm;
	t_vector	color;
	float		ratio;

	color.x = '\0';
	color.y = '\0';
	color.z = '\0';
	norm = vec_subtract(data->hit->cylinder->impact_point,
			data->hit->cylinder->center);
	vec_normalize(&norm);
	*data->hit->cylinder->ray_light =
			vec_subtract(data->hit->cylinder->impact_point,
			data->scene->light->origine);
	vec_normalize(data->hit->cylinder->ray_light);
	ratio = vec_dot_product(&norm, data->hit->cylinder->ray_light);
	if (ratio >= 0)
		color = vec_multiplying(data->white_light, ratio);
	return (color);
}
