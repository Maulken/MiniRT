/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/10/01 10:58:34 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vector	*add_vector_float(t_vector *vec, char *str)
{
	char		**tmp;

	tmp = ft_split(str, ',');
	if (!tmp)
		return (NULL);
	vec->x = ft_atof(tmp[0]);
	vec->y = ft_atof(tmp[1]);
	vec->z = ft_atof(tmp[2]);
	if (vec->x == LERROR || vec->y == LERROR || vec->z == LERROR)
		return (free_tab(tmp), NULL);
	free_tab(tmp);
	return (vec);
}

t_vector	*add_color_int(t_vector *rgb, char *str)
{
	char		**tmp;

	tmp = ft_split(str, ',');
	if (!tmp)
		return (NULL);
	rgb->x = ft_atoi(tmp[0]);
	rgb->y = ft_atoi(tmp[1]);
	rgb->z = ft_atoi(tmp[2]);
	if (rgb->x == IERROR || rgb->y == IERROR || rgb->z == IERROR)
	{
		printf("Error : overflow INT detected\n");
		free_tab(tmp);
		return (NULL);
	}
	if ((rgb->x > 255 || rgb->x < 0)
		|| (rgb->y > 255 || rgb->y < 0)
		|| (rgb->z > 255 || rgb->z < 0))
		return (free_tab(tmp), ft_msg_error("RGB out of range", 1), NULL);
	free_tab(tmp);
	return (rgb);
}
