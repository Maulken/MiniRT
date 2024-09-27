/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:47:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/27 10:43:18 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	error_allocation(void)
{
	printf("Memory allocation failed\n");
	exit(1);
}

int	init_data(t_data *data)
{
	data->white_light.x = 255;
	data->white_light.y = 255;
	data->white_light.z = 255;
	data->view.height = 900;
	data->view.width = 1700;
	data->view.distance = 0;
	data->hit.distance = INFINITY;
	return (0);
}
