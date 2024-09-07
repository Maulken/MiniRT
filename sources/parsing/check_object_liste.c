/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_liste.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktor <viktor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:36:59 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 17:50:04 by viktor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_sphere(char *tab, t_data *data)
{
	t_sphere			*current;
	t_sphere			**last;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 't', 'i', 'v', 'v'};

	current = malloc(sizeof(t_sphere));
	if (current == NULL)
		return (1);
	current->next = NULL;
	if (check_num(tab, "sp", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
		return (free_tab(tmp), free(current), 1);
	if (init_sphere(current, tmp))
		return (free_tab(tmp), 1);
	last = &data->scene->spheres;
	while (*last != NULL)
		last = &(*last)->next;
	*last = current;
	free_tab(tmp);
	return (0);
}

int	init_plane(t_plane *current, char **tmp)
{
	current->origine = add_vector_float(tmp[1]);
	current->direction = add_vector_float(tmp[2]);
	if (check_vector_normalised(current->direction))
	{
		printf("ERROR : invalid vector plese [0][1]");
		return (1);
	}
	current->color = add_color_int(tmp[3]);
	current->impact_point = NULL;
	current->ray = NULL;
	current->ray_light = NULL;
	return (0);
}

int	check_plane(char *tab, t_data *data)
{
	t_plane				*current;
	t_plane				**last;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 'i', 'v', 'v'};

	current = malloc(sizeof(t_plane));
	if (current == NULL)
		return (1);
	current->next = NULL;
	if (check_num(tab, "pl", 4))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
		return (free_tab(tmp), free(current), 1);
	if (init_plane(current, tmp))
		return (free_tab(tmp), 1);
	last = &data->scene->plane;
	while (*last != NULL)
		last = &(*last)->next;
	*last = current;
	free_tab(tmp);
	return (0);
}

int	init_cylinder(t_cylinder *current, char **tmp)
{
	current->center = add_vector_float(tmp[1]);
	current->direction = add_vector_float(tmp[2]);
	if (check_vector_normalised(current->direction))
	{
		printf("ERROR : invalid direction");
		return (1);
	}
	current->diameter = ft_atof(tmp[3]);
	current->height = ft_atof(tmp[4]);
	current->color = add_color_int(tmp[5]);
	current->impact_point = NULL;
	current->ray = NULL;
	current->ray_light = NULL;
	return (0);
}

int	check_cylinder(char *tab, t_data *data)
{
	t_cylinder			*current;
	t_cylinder			**last;
	char				**tmp;
	static const char	content[6] = {'c', 'f', 'f', 't', 't', 'i'};

	current = malloc(sizeof(t_cylinder));
	if (current == NULL)
		return (1);
	current->next = NULL;
	if (check_num(tab, "cy", 6))
		return (1);
	tmp = check_correct_type(content, tab);
	if (tmp == NULL)
		return (free_tab(tmp), free(current), 1);
	if (init_cylinder(current, tmp) == 1)
		return (free_tab(tmp), 1);
	last = &data->scene->cylinder;
	while (*last != NULL)
		last = &(*last)->next;
	*last = current;
	free_tab(tmp);
	return (0);
}
