/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/09/12 20:30:51 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

// TODO: Malloc non protege !
t_vector	*add_vector_float(t_vector *vec, char *str)
{
	char		**tmp;

	tmp = ft_split(str, ',');
	vec->x = ft_atof(tmp[0]);
	vec->y = ft_atof(tmp[1]);
	vec->z = ft_atof(tmp[2]);
	free_tab(tmp);
	return (vec);
}

t_vector	*add_color_int(t_vector *rgb, char *str)
{
	char		**tmp;

	tmp = ft_split(str, ',');
	if (!tmp)
		return (NULL);
	rgb->x = (float)ft_atoi(tmp[0]);
	rgb->y = ft_atoi(tmp[1]);
	rgb->z = ft_atoi(tmp[2]);
	checking_limit(rgb->x, 0.0f, 255.0f);
	checking_limit(rgb->y, 0.0f, 255.0f);
	checking_limit(rgb->z, 0.0f, 255.0f);
	free_tab(tmp);
	return (rgb);
}
