/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/08/20 09:48:43 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	color_max_min(t_vector *rgb)
{
	if (rgb->x > 255)
		rgb->x = 255;
	if (rgb->x < 0)
		rgb->y = 0;
	if (rgb->y > 255)
		rgb->y = 255;
	if (rgb->y < 0)
		rgb->z = 0;
	if (rgb->z > 255)
		rgb->z = 255;
	if (rgb->z < 0)
		rgb->z = 0;
}

t_vector	*add_vector_float(char *str)
{
	char		**tmp;
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
	{
		return (NULL);
	}
	tmp = ft_split(str, ',');
	vector->x = ft_atof_custom(tmp[0]);
	vector->y = ft_atof_custom(tmp[1]);
	vector->z = ft_atof_custom(tmp[2]);
	free_tab(tmp);
	return (vector);
}

t_vector	*add_color_int(char *str)
{
	char		**tmp;
	t_vector	*rgb;

	rgb = malloc(sizeof(t_vector));
	if (!rgb)
		return (NULL);
	tmp = ft_split(str, ',');
	if (!tmp)
		return (NULL);
	rgb->x = ft_atoi(tmp[0]);
	rgb->y = ft_atoi(tmp[1]);
	rgb->z = ft_atoi(tmp[2]);
	color_max_min(rgb);
	free_tab(tmp);
	return (rgb);
}

int	add_int(char *str)
{
	return (ft_atoi(str));
}

float	add_float(char *str)
{
	return (ft_atof_custom(str));
}
