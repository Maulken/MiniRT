/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/19 20:19:46 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	checking_limit_color(t_vector *colors)
{
	if (colors->x > 255)
		colors->x = 255;
	if (colors->y > 255)
		colors->y = 255;
	if (colors->z > 255)
		colors->z = 255;
	if (colors->x < 0)
		colors->x = 0;
	if (colors->y < 0)
		colors->y = 0;
	if (colors->z < 0)
		colors->z = 0;
}

int	create_rgb(t_vector *colors)
{
	return ((int)colors->x << 16 | (int)colors->y << 8 | (int)colors->z);
}

void	my_mlx_pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->addr + (data->mlx_y * data->line_length + data->mlx_x *
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
