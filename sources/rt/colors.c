/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:37 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 13:03:10 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	checking_limit_color(t_color *colors)
{
	if (colors->r > 255)
		colors->r = 255;
	if (colors->g > 255)
		colors->g = 255;
	if (colors->b > 255)
		colors->b = 255;
	if (colors->r < 0)
		colors->r = 0;
	if (colors->g < 0)
		colors->g = 0;
	if (colors->b < 0)
		colors->b = 0;
}

t_color	*multiplying_coef_color(float coef, t_color *colors)
{
	t_color	*new_color;

	new_color = malloc(sizeof(t_color));
	if (!new_color)
		return (0);
	new_color->r = colors->r * coef;
	new_color->g = colors->g * coef;
	new_color->b = colors->b * coef;
	checking_limit_color(new_color);
	return (new_color);
}

t_color	*addition_color(t_color *color1, t_color * color2)
{
	t_color	*new_color;

	new_color = malloc(sizeof(t_color));
	if (!new_color)
		return (NULL);
	new_color->r = color1->r + color2->r;
	new_color->g = color1->g + color2->g;
	new_color->b = color1->b + color2->b;
	checking_limit_color(new_color);
	return (new_color);
}

int	create_rgb(t_color *colors)
{
	return (colors->r << 16 | colors->g << 8 | colors->b);
}

void	my_mlx_pixel_put(t_data *data, int color)
{
	char	*dst;

	dst = data->addr + (data->mlx_y * data->line_length + data->mlx_x *
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
