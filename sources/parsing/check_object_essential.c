/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_essential.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktor <viktor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 17:20:24 by viktor           ###   ########.fr       */
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
		printf("\033[38;5;208m WARNING: The vector"
			"is not normalized. \033[0m \n");
	return (0);
}

int	check_ambiance(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 't', 'i', 'v', 'v', 'v'};

	if (check_num(tab, "A", 3))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free_tab(tmp);
		return (1);
	}
	data->scene->ambient->ratio = ft_atof(tmp[1]);
	data->scene->ambient->colors = add_color_int(tmp[2]);
	*data->scene->ambient->ambient_light = vec_multiplying(
			data->scene->ambient->colors, data->scene->ambient->ratio);
	free_tab(tmp);
	return (0);
}

int	check_camera(char *tab, t_data *data)
{
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 't', 'v', 'v'};

	if (check_num(tab, "C", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
		return (1);
	data->scene->camera->origine = add_vector_float(tmp[1]);
	data->scene->camera->direction = add_vector_float(tmp[2]);
	if (check_vector_normalised(data->scene->camera->direction))
	{
		printf("ERROR : invalid Orientation");
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

	if (check_num(tab, "L", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
	{
		free(tmp);
		return (1);
	}
	data->scene->light->origine = add_vector_float(tmp[1]);
	data->scene->light->ratio = ft_atof(tmp[2]);
	free_tab(tmp);
	return (0);
}
