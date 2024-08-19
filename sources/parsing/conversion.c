/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/08/19 20:31:26 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector *add_vector_float(char *str) //  pas de gestion en cas double point .....
{
	char **tmp;
	t_vector *vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
	{
		return(NULL);
	}
	tmp = ft_split(str,',');
	vector->x = ft_atof_custom(tmp[0]);
	vector->y = ft_atof_custom(tmp[1]);
	vector->z = ft_atof_custom(tmp[2]);
	free_tab(tmp);
	return(vector);
}

t_vector    *add_color_int(char *str)
{
	 char **tmp;
	t_vector *rgb;
	
	rgb = malloc(sizeof(t_vector));
	if (!rgb)
		return (NULL);
	tmp = ft_split(str,',');
	if (!tmp)
		return (NULL);
	rgb->x = ft_atoi(tmp[0]);
	rgb->y = ft_atoi(tmp[1]);
	rgb->z = ft_atoi(tmp[2]);
	checking_limit_color(rgb);
	free_tab(tmp);
	return(rgb);
}

int add_int(char *str)
{
return(ft_atoi(str));
}

float add_float(char *str)
{
return(ft_atof_custom(str));
}

