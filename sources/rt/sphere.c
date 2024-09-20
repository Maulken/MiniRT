/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:41:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/20 10:52:56 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define NEAR 0.01
#define FAR 250.0

// b = sphere_dir . ray.dir
// c = b * b - |ray.dir| * (|sphere_dir|^2 - (diameter / 2)^2)
float	sphere_intersect(t_geometry *sph, t_vector *origin, t_vector *dir)
{
	t_vector	sphere_dir;
	float		b;
	float		c;
	float		root;

	vec_subtract(&sphere_dir, origin, &sph->data.sphere.center);
	b = vec_dot_product(&sphere_dir, dir);
	c = vec_length2(&sphere_dir);
	c -= sph->data.sphere.diameter * sph->data.sphere.diameter / 4.;
	c *= vec_lenght(dir);
	c = b * b - c;
	if (c < 0)
		return (-1);
	root = (-b - sqrt(c)) / vec_length2(dir);
	if (root < NEAR || root > FAR)
		root = (-b + sqrt(c)) / vec_length2(dir);
	if (root < NEAR || root > FAR)
		return (-1);
	return (root);
}

int	get_color_sphere(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	hit->geometry->dist_cam = sphere_intersect(hit->geometry,
			&hit->geometry->ray.origin, &hit->geometry->ray.dir);
	if (hit->geometry->dist_cam <= 0)
		return (0x3300ff);
	mix_color = data->scene->ambient->ambient_light;
	get_diffuse_light_sp(data, hit, &diffuse_light);
	if (diffuse_light.x)
		vec_add(&mix_color, &data->scene->ambient->ambient_light,
			&diffuse_light);
	vec_add(&mix_color, &hit->geometry->color, &mix_color);
	limit_color(&mix_color);
	new_color = create_rgb(&mix_color);
	return (new_color);
}

void	is_sphere(t_data *data, t_scene tmp)
{
	float	dist;

	dist = sphere_intersect(tmp.objects, &tmp.objects->ray.origin,
			&tmp.objects->ray.dir);
	if (dist < data->hit.distance && dist >= 0)
	{
		data->hit.distance = dist;
		data->hit.geometry = tmp.objects;
	}
}
