/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/22 08:58:28 by mpelluet         ###   ########.fr       */
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

void	limit_color(t_vector *color)
{
	color->x = checking_limit(color->x / 2., 0.0f, 255.0f);
	color->y = checking_limit(color->y / 2., 0.0f, 255.0f);
	color->z = checking_limit(color->z / 2., 0.0f, 255.0f);
}
