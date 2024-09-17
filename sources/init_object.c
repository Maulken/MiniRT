/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:25:01 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/12 20:30:10 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	init_geometry(t_geometry *geometry)
{
	*geometry = (t_geometry){0};
	geometry->dist_light = -1;
	geometry->dist_cam = -1;
}
