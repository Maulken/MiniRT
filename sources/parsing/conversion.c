/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/08/15 09:20:06 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_cord *add_cord_float(char *str) //  pas de gestion en cas double point .....
{
    char **tmp;
    t_cord *cord;

    cord = malloc(sizeof(t_cord));
    tmp = ft_split(str,',');
    cord->x = ft_atof_custom(tmp[0]);
    cord->y = ft_atof_custom(tmp[1]);
    cord->z = ft_atof_custom(tmp[2]);
    return(cord);
}

t_cord    *add_cord_int(char *str) //usless ????
{
    char **tmp;
    t_cord *cord;

    tmp = ft_split(str,',');
    cord->x = ft_atoi(tmp[0]);
    cord->y = ft_atoi(tmp[1]);
    cord->z = ft_atoi(tmp[2]);
    return(cord);
}

int add_int(char *str)
{
return(ft_atoi(str));
}

float add_float(char *str)
{
return( ft_atof_custom(str));
}

t_colors add_rgb(char *str)
{
      char **tmp;
    t_colors rgb;

    tmp = ft_split(str,',');
    rgb.r = ft_atoi(tmp[0]);
    if(rgb.r > 255)
        rgb.r = 255;
    if(rgb.r > 0)
        rgb.r = 0;
  
    return(rgb);

}

