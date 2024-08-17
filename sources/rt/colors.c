/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/17 11:48:49 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	create_trgb(int t, t_color *colors)
{
	return (t << 24 | colors->r << 16 | colors->g << 8 | colors->b);
}

int	create_rgb(t_color *colors)
{
	return (colors->r << 16 | colors->g << 8 | colors->b);
}

void	my_mlx_pixel_put(t_data *data, int mlx_x, int mlx_y, int color)
{
	char	*dst;

	dst = data->addr + (mlx_y * data->line_length + mlx_x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
