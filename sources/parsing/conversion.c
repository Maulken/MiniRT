/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/08/15 20:08:50 by vharatyk         ###   ########.fr       */
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
    return(vector);
}

t_color    *add_color_int(char *str)
{
     char **tmp;
    t_color *rgb;
    
    rgb = malloc(sizeof(t_color));
    if (!rgb)
        return (NULL);
    tmp = ft_split(str,',');
    if (!tmp)
        return (NULL);
    rgb->r = ft_atoi(tmp[0]);
    if(rgb->r > 255)
        rgb->r = 255;
    if(rgb->r < 0)
        rgb->r = 0;
    rgb->g = ft_atoi(tmp[1]);
    if(rgb->g > 255)
        rgb->g = 255;
    if(rgb->g < 0)
        rgb->g = 0;
    rgb->b = ft_atoi(tmp[2]);
    if(rgb->b > 255)
        rgb->b = 255;
    if(rgb->b < 0)
        rgb->b = 0;
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

