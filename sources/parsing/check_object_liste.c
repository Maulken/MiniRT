/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_liste.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:36:59 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/25 17:44:17 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_sphere(char *tab, t_data *data)
{
	t_geometry			*current;
	t_geometry			**last;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 't', 'i', 'v', 'v'};

	current = calloc(1, sizeof(t_geometry));
	if (current == NULL)
		return (1);
	tmp = check_correct_type(content, tab, "sp", 4);
	if (tmp == NULL)
		return (free_tab(tmp), free(current), 1);
	if (init_sphere(current, tmp))
		return (free_tab(tmp), 1);
	last = &data->scene->objects;
	while (*last != NULL)
		last = &(*last)->next;
	*last = current;
	free_tab(tmp);
	return (0);
}

int	init_plane(t_geometry *current, char **tmp)
{
	t_plane *const	plane = &current->data.plane;

	current->type = GT_PLANE;
	add_vector_float(&plane->origine, tmp[1]);
	add_vector_float(&plane->direction, tmp[2]);
	add_color_int(&current->color, tmp[3]);
	if (!check_vector_normalised(&plane->direction))
		return (0);
	printf("ERROR : invalid vector plese [0][1]");
	return (1);
}

int	check_plane(char *tab, t_data *data)
{
	static const char	content[6] = {'c', 'f', 'f', 'i', 'v', 'v'};
	t_geometry			*current;
	t_geometry			**last;
	char				**tmp;

	current = calloc(1, sizeof(t_geometry));
	if (current == NULL)
		return (1);
	tmp = check_correct_type(content, tab, "pl", 4);
	if (tmp == NULL)
		return (free_tab(tmp), free(current), 1);
	if (init_plane(current, tmp))
		return (free_tab(tmp), 1);
	last = &data->scene->objects;
	while (*last != NULL)
		last = &(*last)->next;
	*last = current;
	free_tab(tmp);
	return (0);
}

int	init_cylinder(t_geometry *current, char **tmp)
{
	t_cylinder *const	cylinder = &current->data.cylinder;

	current->type = GT_CYLINDER;
	add_vector_float(&cylinder->center, tmp[1]);
	add_vector_float(&cylinder->direction, tmp[2]);
	if (check_vector_normalised(&cylinder->direction))
		return (printf("ERROR : invalid direction"), 1);
	cylinder->diameter = ft_atof(tmp[3]);
	cylinder->height = ft_atof(tmp[4]);
	add_color_int(&current->color, tmp[5]);
	return (0);
}

int	check_cylinder(char *tab, t_data *data)
{
	t_geometry			*current;
	t_geometry			**last;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 't', 't', 'i'};

	current = calloc(1, sizeof(t_geometry));
	if (current == NULL)
		return (1);
	tmp = check_correct_type(content, tab, "cy", 6);
	if (tmp == NULL)
		return (free_tab(tmp), free(current), 1);
	if (init_cylinder(current, tmp) == 1)
		return (free_tab(tmp), 1);
	last = &data->scene->objects;
	while (*last != NULL)
		last = &(*last)->next;
	*last = current;
	free_tab(tmp);
	return (0);
}
