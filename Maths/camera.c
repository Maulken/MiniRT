/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:22:05 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/14 17:32:45 by vmassoli         ###   ########.fr       */
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
