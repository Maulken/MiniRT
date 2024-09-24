/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/23 17:08:17 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define BACKGROUND_COLOR 0x3300ff

void	get_view_plane(t_data *data)
{
	t_vector	up_y;

	up_y = (t_vector){0, 1, 0};
	data->view.distance = 1. / (tanf(M_PI * data->scene->camera->fov / 360.));
	vec_normalize(vec_cross(&data->view.viewplane_x,
			&data->scene->camera->direction, &up_y));
	vec_normalize(vec_cross(&data->view.viewplane_y,
			&data->scene->camera->direction, &data->view.viewplane_x));
}

void	obtain_ray(t_data *data, t_vector *rx, t_vector *ry, t_vector *ray)
{
	t_vector	ray_without_z;
	t_vector	z;

	vec_add(&ray_without_z, rx, ry);
	vec_multiplying(&z, &data->scene->camera->direction, data->view.distance);
	vec_add(ray,
		&data->scene->camera->origine,
		vec_add(ray, &ray_without_z, &z));
}

void	get_hit(t_data *data, t_scene tmp, t_vector *rx, t_vector *ry)
{
	while (tmp.objects)
	{

		obtain_ray(data, rx, ry, &tmp.objects->ray.origin);
		vec_normalize(vec_subtract(&tmp.objects->ray.dir,
				&tmp.objects->ray.origin, &data->scene->camera->origine));
		if (tmp.objects->type == GT_SPHERE)
			is_sphere(data, tmp);
		if (tmp.objects->type == GT_PLANE)
			is_plane(data, tmp);
		if (tmp.objects->type == GT_CYLINDER)
			is_cylinder(data, tmp);
		tmp.objects = tmp.objects->next;
	}
}

int	get_color(t_data *data, t_vector *x_ray, t_vector *y_ray)
{
	data->hit.distance = INFINITY;
	get_hit(data, *data->scene, x_ray, y_ray);
	if (data->hit.geometry == NULL)
		return (BACKGROUND_COLOR);
	if (data->hit.geometry->type == GT_SPHERE)
		return (get_color_sphere(data, &data->hit));
	if (data->hit.geometry->type == GT_PLANE)
		return (get_color_plane(data));
	if (data->hit.geometry->type == GT_CYLINDER)
		return (get_mix_color(data, &data->hit));
	return (BACKGROUND_COLOR);
}

void	ray_tracing(t_data *data)
{
	const float	ar = (float)data->view.width / (float)data->view.height;
	t_vector	pos;
	t_vector	x_ray;
	t_vector	y_ray;

	x_ray = (t_vector){0};
	y_ray = (t_vector){0};
	pos = (t_vector){0};
	get_view_plane(data);
	data->mlx_y = 0;
	while (data->mlx_y < data->view.height)
	{
		pos.y = (2 * data->mlx_y - data->view.height) / data->view.height;
		vec_multiplying(&y_ray, &data->view.viewplane_y, pos.y);
		data->mlx_x = 0;
		while (data->mlx_x < data->view.width)
		{
			pos.x = (2 * data->mlx_x - data->view.width) / data->view.width;
			vec_multiplying(&x_ray, &data->view.viewplane_x, ar * pos.x);
			my_mlx_pixel_put(data, get_color(data, &x_ray, &y_ray));
			data->mlx_x++;
		}
		data->mlx_y++;
	}
}
