/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:41:08 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/18 16:08:40 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

#define NEAR 0.01
#define FAR 250.0

// b = sphere_dir . ray.dir
// c = b * b - |ray.dir| * (|sphere_dir|^2 - (diameter / 2)^2)
// float	sphere_intersect(t_geometry *sph)
// {
// 	t_vector	sphere_dir;
// 	float		b;
// 	float		c;
// 	float		root;

// 	vec_subtract(&sphere_dir, &sph->ray.origin, &sph->data.sphere.center);
// 	b = vec_dot_product(&sphere_dir, &sph->ray.dir);
// 	c = vec_length2(&sphere_dir);
// 	c -= sph->data.sphere.diameter * sph->data.sphere.diameter / 4.;
// 	c *= vec_lenght(&sph->ray.dir);
// 	c = b * b - c;
// 	if (c < 0)
// 		return (-1);
// 	root = (-b - sqrt(c)) / vec_length2(&sph->ray.dir);
// 	if (root < NEAR || root > FAR)
// 		root = (-b + sqrt(c)) / vec_length2(&sph->ray.dir);
// 	if (root < NEAR || root > FAR)
// 		return (-1);
// 	return (root);
// }
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

bool	is_obstacle(t_scene tmp, t_hit *hit)
{
	t_vector	ray;

	vec_multiplying(&ray, &hit->geometry->ray.light, -1.);
	while (tmp.objects)
	{
		if (tmp.objects->type == GT_SPHERE
			&& sphere_intersect(tmp.objects,
				&hit->geometry->impact_point, &ray) >= 0)
			return (true);
		else if (tmp.objects->type == GT_PLANE
			&& plane_intersect(tmp.objects,
				&hit->geometry->impact_point, &ray) >= 0)
			return (true);
		tmp.objects = tmp.objects->next;
	}
	return (false);
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
	if (is_obstacle(*data->scene, hit) == false)
	{
		vec_normalize(vec_subtract(&norm, &hit->geometry->impact_point,
				&hit->geometry->data.sphere.center));
		vec_normalize(vec_subtract(&hit->geometry->ray.light,
				&data->scene->light->origine, &hit->geometry->impact_point));
		ratio = vec_dot_product(&norm, &hit->geometry->ray.light);
		*color = (t_vector){0};
		if (ratio >= 0)
			vec_multiplying(color, &data->white_light, ratio);
	}
}

int	get_color_sphere(t_data *data, t_hit *hit)
{
	int			new_color;
	t_vector	diffuse_light;
	t_vector	mix_color;

	// hit->geometry->dist_cam = sphere_intersect(hit->geometry);
	hit->geometry->dist_cam = sphere_intersect(hit->geometry, 
			&hit->geometry->ray.origin, &hit->geometry->ray.dir);
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
