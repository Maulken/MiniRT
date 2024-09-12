/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:35:05 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/12 17:09:16 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	free_geometry_list(t_geometry *geometry)
{
	if (geometry->next)
		free_geometry_list(geometry->next);
	free(geometry);
}
