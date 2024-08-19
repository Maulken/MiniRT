/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:57 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/19 19:51:57 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	get_view_plane(t_data *data)
{
	float	aspect_ratio;
	float	width;
	float	height;

	aspect_ratio = data->view->width / data->view->height;
	width = 2 * tan(data->scene->camera->fov / 2 * (M_PI / 180));
	height = width / aspect_ratio;
	data->view->x_pixel = width / data->view->width;
	data->view->y_pixel = height / data->view->height;
}

void	obtain_ray(t_data *data, float x_ray, float y_ray)
{
	t_vector	*for_ray;
	// data->scene->spheres->impact_point = new_vector(x_ray, y_ray,
	// 		data->scene->camera->direction->z);
	// data->scene->spheres->ray = vec_subtract(data->scene->spheres->impact_point,
	// 		data->scene->camera->origine);
	
	// for_ray permet de convertir nos coordonnees pixel en coordonnees x,y,z sur le plan
	for_ray = new_vector(x_ray, y_ray, data->scene->camera->direction->z);
	
	data->scene->spheres->ray = vec_subtract(for_ray,
			data->scene->camera->origine);
	// data->scene->spheres->ray_light = vec_subtract(data->scene->spheres->ray,
	// 		data->scene->light->origine); weird
	// data->scene->spheres->ray_light = vec_subtract(data->scene->spheres->impact_point,
	// 	data->scene->light->origine);
	// printf("lenght raylight %f\n", vec_lenght(data->scene->spheres->ray_light, data->scene->spheres->ray_light));
	vec_normalize(data->scene->spheres->ray);
	// vec_normalize(data->scene->spheres->ray_light);
	// printf("lenght raylight N %f\n", vec_lenght(data->scene->spheres->ray_light, data->scene->spheres->ray_light));
}

// void	obtain_ray(float x, float y, float z, t_vector *ray, t_vector *origin)
// {
// 	t_vector	*position;

// 	position = new_vector(x, y, z);
// 	ray = vec_subtract(position, origin);
// 	vec_normalize(ray);
// }

// float	sphere_intersect(t_data *data, t_situation situation)
// {
// 	float	b;
// 	float	c;
// 	float	discr;
// 	float	dist1;
// 	float	dist2;
// 	float	dot_p;
// 	float	rayon;
// 	t_vector	*origine_sphere;

// 	dist1 = 0;
// 	dist2 = 0;
// 	if (situation == CAMERA)
// 	{
// 		origine_sphere = vec_subtract(data->scene->camera->origine,
// 				data->scene->spheres->center);
// 		b = 2 * (vec_dot_product(origine_sphere, data->scene->spheres->ray));
// 		rayon = data->scene->spheres->diameter / 2;
// 		dot_p = vec_dot_product(origine_sphere, origine_sphere);
// 	}
// 	else
// 	{
// 		origine_sphere = vec_subtract(data->scene->light->origine,
// 				data->scene->spheres->center);
// 		// printf("origine sphere %f %f %f\n", origine_sphere->x, origine_sphere->y, origine_sphere->z);
// 		b = 2 * (vec_dot_product(origine_sphere, data->scene->spheres->ray_light));
// 		// printf("b2 %f\n", (b * b));
// 		rayon = data->scene->spheres->diameter / 2;
// 		dot_p = vec_dot_product(origine_sphere, origine_sphere);
// 		// printf("4dot p %f\n", (dot_p * 4));
// 	}
// 	// c = vec_dot_product(origine_sphere, origine_sphere)
// 	// 	- ((data->scene->spheres->diameter / 2)
// 	// 		* (data->scene->spheres->diameter / 2));
// 	c =  dot_p - (rayon * rayon);
// 	// printf("c %f\n", c);
// 	discr = (b * b) - (4 * c);
// 	free(origine_sphere);
// 	if (discr < 0)
// 		return (0);
// 	dist1 = ((b * (-1)) - sqrtf(discr)) / 2;
// 	dist2 = ((b * (-1)) + sqrtf(discr)) / 2;
// 	// printf("dist1 %f\ndist2 %f\n", dist1, dist2);
// 	if (dist1 > 0)
// 		return (dist1);
// 	return (0);
// }

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
	if (quadratic_equation(dist, 1, b, c))
		return (EXIT_FAILURE);
	if (dist[0] < dist[1])
		return (dist[0]);
	return (dist[1]);
}

// bool	is_light_intersect(t_light *light, t_sphere *sphere, t_camera *cam)
// {
// 	t_vector	*light_point;
	
// 	sphere->impact_point = vec_add(cam->origine,
// 				vec_multiplying(sphere->ray, sphere->dist_cam_sphere));
	
// 	sphere->ray_light = vec_subtract(sphere->impact_point, light->origine);
// 	vec_normalize(sphere->ray_light);
	
// 	sphere->dist_light_sphere = sphere_intersect(light->origine,
// 		sphere->ray_light, sphere);
// 	printf("dist ligth sp %f\n", sphere->dist_light_sphere);
	
// 	if (sphere->dist_light_sphere > 0 && sphere->dist_light_sphere
// 		!= EXIT_FAILURE)
// 	{
// 		// printf("la\n");
// 		light_point = vec_add(light->origine,
// 				vec_multiplying(sphere->ray_light, sphere->dist_light_sphere));
// 		// printf("changement de printf\n");
		
// 		printf("light %f %f %f\nimpact %f %f %f\n", light_point->x, light_point->y, light_point->z, sphere->impact_point->x, sphere->impact_point->y, sphere->impact_point->z);
// 		if (vec_compare(light_point, sphere->impact_point))
// 		{
// 			printf("comapre\n");
// 			return (true);
// 		}
// 	}
// 	return (false);
// }

// float	get_light_coef(t_data *data)
// {
// 	float		light_coef;
// 	float		dot_p;
// 	float		length_p;
// 	t_scene		*scene;
// 	t_vector	*sphere_normale;

// 	scene = data->scene;
// 	sphere_normale = vec_subtract(scene->spheres->impact_point,
// 		scene->spheres->center);
// 	vec_normalize(sphere_normale);
// 	dot_p = vec_dot_product(scene->spheres->ray_light, sphere_normale);
// 	length_p = (data->scene->spheres->dist_light_sphere
// 		* (scene->spheres->diameter / 2));
// 	light_coef = dot_p / length_p;
// 	printf("dot_p %f\n", dot_p);
// 	printf("lenght_p %f\n", length_p);
// 	return (light_coef);
// }

t_vector	*get_diffuse_light(t_data *data)
{
	t_vector	*ray_light;
	t_vector	*norm;
	t_vector	*color;
	float		coef;

	ray_light = data->scene->spheres->ray_light;
	data->scene->spheres->impact_point = vec_add(data->scene->camera->origine,
		vec_multiplying(data->scene->spheres->ray,
		data->scene->spheres->dist_cam_sphere));
	norm = vec_subtract(data->scene->spheres->impact_point,
		data->scene->spheres->center);
	vec_normalize(norm);
	ray_light = vec_subtract(data->scene->spheres->impact_point,
		data->scene->light->origine);
	vec_normalize(ray_light);
	coef = vec_dot_product(norm, ray_light);
	color = vec_multiplying(data->white_light, coef);
	return (color);
}

int	get_color(t_data *data)
{
	int			new_color;
	t_vector	*ambient_light;
	t_vector	*diffuse_light;
	t_vector	*mix_color;
	t_scene		*scene;
	
	
	new_color = 0;
	scene = data->scene;
	scene->spheres->dist_cam_sphere = sphere_intersect(scene->camera->origine,
		scene->spheres->ray, scene->spheres);
	if (scene->spheres->dist_cam_sphere > 0 && scene->spheres->dist_cam_sphere
		!= EXIT_FAILURE)
	{
		ambient_light = vec_multiplying(scene->ambient->colors,
			scene->ambient->ratio);
		diffuse_light = get_diffuse_light(data);
		mix_color = vec_add(ambient_light, diffuse_light);
		mix_color = vec_add(data->scene->spheres->color, mix_color);
		new_color = create_rgb(mix_color);
		// printf("new_color %d\n", new_color);
	}
	return (new_color);
}

// int	get_color(t_data *data)
// {
// 	float	light_coef;
// 	t_vector	*color_with_light;
// 	t_sphere	*sphere;

// 	light_coef = 0;
// 	sphere = data->scene->spheres;
// 	sphere->dist_cam_sphere = sphere_intersect(data->scene->camera->origine,
// 		sphere->ray, sphere);
// 	// printf("dist cam sphe %f\n", sphere->dist_cam_sphere);
// 	if (sphere->dist_cam_sphere > 0 && sphere->dist_cam_sphere != EXIT_FAILURE)
// 	{
// 		printf("avant is_light\n"); 
// 		if (is_light_intersect(data->scene->light, sphere, data->scene->camera))
// 		{
// 			light_coef = get_light_coef(data);
// 			printf("light coef %f\n", light_coef);
// 			color_with_light = vec_add(data->scene->spheres->color,
// 				vec_multiplying(data->white_light, light_coef));
// 			return (create_rgb(color_with_light));
// 		}
// 		else
// 			return (create_rgb(data->scene->spheres->color));
// 	}
// 	return (0);
// }

void	ray_tracing(void *mlx, void *window, t_data *data)
{
	float		x_scale;
	float		y_scale;
	float		x_ray;
	float		y_ray;

	get_view_plane(data);
	data->mlx_y = 0;
	y_scale = (data->view->height / 2);
	while (y_scale >= (data->view->height / 2) * (-1))
	{
		y_ray = y_scale * data->view->y_pixel;
		x_scale = (data->view->width / 2) * (-1);
		data->mlx_x = 0;
		while (x_scale <= data->view->width / 2)
		{
			x_ray = x_scale * data->view->x_pixel;
			obtain_ray(data, x_ray, y_ray);
			// obtain_ray(x_ray, y_ray, data->scene->camera->direction->z,
			// 	data->scene->spheres->ray, data->scene->camera->origine);
			// printf("ray %f %f %f\n", data->scene->spheres->ray->x, data->scene->spheres->ray->y, data->scene->spheres->ray->z);
			my_mlx_pixel_put(data, get_color(data));
			x_scale++;
			data->mlx_x++;
		}
		y_scale--;
		data->mlx_y++;
	}
}




	// lenght_normal = data->scene->spheres->diameter / 2;
	// lenght_light = sphere_intersect(data->scene->light->origine, ray, data->scene->spheres);
//!\ sphere intersect = a readapter

	// valeur vect temp
	// angle en absolu
	// norme point d insection
	// arcos(nor * dot prod)

// }

// trouver theta:

// 	scalaire de light normale
// 	longueur Light
// 	longueur norm
// 	diviser scalaire par l light *l Norm
// 	arc cos
// acos()

// probleme avec la fonction cree couleur trgb