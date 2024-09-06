/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:36:52 by vharatyk          #+#    #+#             */
/*   Updated: 2024/09/06 13:52:52 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	free_cylinder(t_cylinder *cylinder)
{
	if (cylinder == NULL)
		return ;
	if (cylinder->center != NULL)
		free(cylinder->center);
	if (cylinder->color != NULL)
		free(cylinder->color);
	if (cylinder->direction != NULL)
		free(cylinder->direction);
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
