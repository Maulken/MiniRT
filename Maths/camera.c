/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:22:05 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/15 12:14:36 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*new_camera(t_vector *origine, t_vector *direction, float fov)
{
	t_camera *cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return(NULL);
	cam->origine = origine;
	cam->direction = direction;
	cam->fov = fov;
	return(cam);
}

t_colors	*new_colors(int r, int g, int b)
{
	t_colors *colors;

	colors = malloc(sizeof(t_colors));
	if (!colors)
		return (NULL);
	colors->r = r;
	colors->g = g;
	colors->b = b;
	return (colors);
}
