/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:11:07 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/14 17:54:44 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere *new_sphere(t_vector *center, float diameter)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if(!sphere)
		return(NULL);
	sphere->center = center;
	sphere->diameter = diameter;
	return(sphere);
}

// t_plane	*new_plane(t_vector *origine, t_vector *direction, float fov)
// {
// 	t_plane	*plane;

// 	plane = malloc(sizeof(t_plane));
// 	if(!plane)
// 		return(NULL);
// 	plane->origine = origine;
// 	plane->direction = direction;
// 	return(plane);
// }
// t_cylinder	*new_cylinder(t_vector *center, t_vector *direction, float diameter, float height)
// {
// 	t_cylinder	*cylinder;

// 	cylinder = malloc(sizeof(t_cylinder));
// 	if(!cylinder)
// 		return(NULL);
// 	cylinder->center = center;
// 	cylinder->direction = direction;
// 	cylinder->diameter = diameter;
// 	cylinder->height = height;
// 	return(cylinder);
// }

t_scene	*new_scene(t_camera *cam, t_sphere *sphere)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return(0);
	scene->camera = cam;
	scene->sphere = sphere;
	scene->width = 0;
	scene->height = 0;
	return (scene);
}
