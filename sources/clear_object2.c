/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:36:52 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/22 16:22:25 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	free_cylinder(t_cylinder *cylinder)
{
	if (cylinder == NULL)
		return ;
	if (cylinder->center != NULL)
		free(cylinder->center);
	if (cylinder->color != NULL)
		free(cylinder->color);
	if (cylinder->direction != NULL)
		free(cylinder->direction);
	if (cylinder->impact_point != NULL)
		free(cylinder->impact_point);
	if (cylinder->ray != NULL)
		free(cylinder->ray);
	if (cylinder->ray_light != NULL)
		free(cylinder->ray_light);
	free(cylinder);
}

void	free_cylinder_list(t_cylinder *head)
{
	t_cylinder	*current;
	t_cylinder	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free_cylinder(current);
		current = next;
	}
}
