/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/19 20:32:54 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
void free_vector(t_vector *vector);
void free_rgb(t_vector *color);
int free_lc(t_sphere *head)
{
    t_sphere* current = head;
    t_sphere* nextNode;

    while (current != NULL)
	{
        nextNode = current->next; 
		free_vector(current->center);
		free_rgb(current->color);
        free(current);            
        current = nextNode;  
	}     
    return(0);
}

void free_vector(t_vector *vector)
{
    if (vector != NULL)
	{
        free(vector);
    }
}
void free_rgb(t_vector *color)
{
	if(color != NULL)
		free(color);

}

int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int clean(t_data *data ,int code_error)
{
	free(data->view);

	free_lc(data->scene->spheres);
	//free(data->scene->spheres);
	  
	free_vector(data->scene->camera->direction);
	free_vector(data->scene->camera->origine);
	free(data->scene->camera);

	free(data->scene);
	return(0);
}


