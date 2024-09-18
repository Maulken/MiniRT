/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:41:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/18 10:53:02 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define NEAR 0.01
#define FAR 250.0

// b = sphere_dir . ray.dir
// c = b * b - |ray.dir| * (|sphere_dir|^2 - (diameter / 2)^2)
float	sphere_intersect(t_geometry *sph)
{
	t_vector	sphere_dir;
	float		b;
	float		c;
	float		root;

	vec_subtract(&sphere_dir, &sph->ray.origin, &sph->data.sphere.center);
	b = vec_dot_product(&sphere_dir, &sph->ray.dir);
	c = vec_length2(&sphere_dir);
	c -= sph->data.sphere.diameter * sph->data.sphere.diameter / 4.;
	c *= vec_lenght(&sph->ray.dir);
	c = b * b - c;
	if (c < 0)
		return (-1);
	root = (-b - sqrt(c)) / vec_length2(&sph->ray.dir);
	if (root < NEAR || root > FAR)
		root = (-b + sqrt(c)) / vec_length2(&sph->ray.dir);
	if (root < NEAR || root > FAR)
		return (-1);
	return (root);
}

void	get_diffuse_light(t_data *data, t_hit *hit, t_vector *color)
{
	t_vector	norm;
	t_vector	for_impact_p;
	float		ratio;

	vec_multiplying(&for_impact_p,
		&hit->geometry->ray.dir, hit->geometry->dist_cam);
	vec_add(&hit->geometry->impact_point,
		&hit->geometry->ray.origin, &for_impact_p);
	vec_normalize(vec_subtract(&norm,
			&hit->geometry->impact_point, &hit->geometry->data.sphere.center));
	vec_normalize(vec_subtract(&hit->geometry->ray.light,
			&data->scene->light->origine, &hit->geometry->impact_point));
	ratio = vec_dot_product(&norm, &hit->geometry->ray.light);
	*color = (t_vector){0};
	if (ratio >= 0)
		vec_multiplying(color, &data->white_light, ratio);
}

int	get_color_sphere(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	hit->geometry->dist_cam = sphere_intersect(hit->geometry);
	if (hit->geometry->dist_cam <= 0)
		return (0x3300ff);
	mix_color = data->scene->ambient->ambient_light;
	get_diffuse_light(data, hit, &diffuse_light);
	if (diffuse_light.x)
		vec_add(&mix_color, &data->scene->ambient->ambient_light,
			&diffuse_light);
	vec_add(&mix_color, &hit->geometry->color, &mix_color);
	limit_color(&mix_color);
	new_color = create_rgb(&mix_color);
	return (new_color);
}
