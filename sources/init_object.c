/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:25:01 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/23 15:11:11 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	init_geometry(t_geometry *geometry)
{
	*geometry = (t_geometry){0};
	geometry->in_out = OUTSIDE;
	geometry->dist_cam = -1;
	geometry->id = 0;
}
