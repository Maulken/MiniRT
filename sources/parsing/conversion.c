/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/08/20 16:54:33 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	checking_limit(float a, float min, float max)
{
	if (a < min)
		return (min);
	if (a > max)
		return (max);
	return (a);
}

t_vector	*add_vector_float(char *str)
{
	char		**tmp;
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
	{
		free_tab(tmp);
		return (NULL);
	}
	tmp = ft_split(str, ',');
	vector->x = ft_atof_custom(tmp[0]);
	vector->y = ft_atof_custom(tmp[1]);
	vector->z = ft_atof_custom(tmp[2]);
	printf("%f , %f , %f\n", vector->x, vector->y, vector->z);
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
	rgb->x = (float)ft_atoi(tmp[0]);
	rgb->y = ft_atoi(tmp[1]);
	rgb->z = ft_atoi(tmp[2]);
	checking_limit(rgb->x, 0, 255);
	checking_limit(rgb->y, 0, 255);
	checking_limit(rgb->z, 0, 255);
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
