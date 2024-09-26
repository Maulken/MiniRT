/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_essential.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/26 12:29:13 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	is_normalized(float x, float y, float z)
{
	double	norm;

	norm = 0;
	norm += x * x;
	norm += y * y;
	norm += z * z;
	norm = sqrt(norm);
	return (fabs(norm - 1.0) < 1e-9);
}

int	check_vector_normalised(t_vector *vector)
{
	if (vector->x > 1 || vector->x < -1)
		return (1);
	if (vector->y > 1 || vector->y < -1)
		return (1);
	if (vector->z > 1 || vector->z < -1)
		return (1);
	if (!is_normalized(vector->x, vector->y, vector->z))
		printf("\033[38;5;208m WARNING: The vector "
			"is not normalized. \033[0m \n");
	return (0);
}

int	check_ambiance(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 't', 'i', 'v', 'v', 'v'};

	tmp = check_correct_type(content, tab, "A", 3);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	data->scene->ambient->ratio = ft_atof(tmp[1]);
	add_color_int(&data->scene->ambient->colors, tmp[2]);
	vec_multiplying(&data->scene->ambient->ambient_light,
		&data->scene->ambient->colors, data->scene->ambient->ratio);
	free_tab(tmp);
	return (0);
}

int	check_camera(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 't', 'v', 'v'};

	tmp = check_correct_type(content, tab, "C", 4);
	if (tmp == NULL)
		return (free_tab(tmp), 1);
	add_vector_float(&data->scene->camera->origine, tmp[1]);
	add_vector_float(&data->scene->camera->direction, tmp[2]);
	if (check_vector_normalised(&data->scene->camera->direction))
	{
		printf("ERROR : invalid direction");
		return (free_tab(tmp), 1);
	}
	data->scene->camera->fov = ft_atof(tmp[3]);
	if (data->scene->camera->fov > 180 || data->scene->camera->fov < 0)
	{
		printf("ERROR fov superieur a 180 ou inferieur a 0");
		return (free_tab(tmp), 1);
	}
	free_tab(tmp);
	return (0);
}

int	check_light(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 'f', 't', 'i', 'v', 'v'};

	tmp = check_correct_type(content, tab, "L", 4);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	add_vector_float(&data->scene->light->origine, tmp[1]);
	data->scene->light->ratio = ft_atof(tmp[2]);
	free_tab(tmp);
	return (0);
}
