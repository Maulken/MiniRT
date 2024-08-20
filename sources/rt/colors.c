/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/20 18:06:53 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	create_rgb(t_vector *colors)
{
	int	color;

	color = 0;
	color = ((int)colors->x) << 16 | ((int)colors->y) << 8 | ((int)colors->z);
	return (color);
}

void	my_mlx_pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->addr + (data->mlx_y * data->line_length + data->mlx_x *
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
