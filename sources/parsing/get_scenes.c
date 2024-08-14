/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scenes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:23:43 by viktor            #+#    #+#             */
/*   Updated: 2024/08/14 10:30:35 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_cord add_cord_float(char *str) //  pas de gestion en cas double point .....
{
    char **tmp;
    t_cord cord;

    tmp = ft_split(str,',');
    cord.x = ft_atof(tmp[0]);
    cord.y = ft_atof(tmp[1]);
    cord.z = ft_atof(tmp[2]);
    return(cord);
}

t_cord    add_cord_int(char *str) //usless ????
{
    char **tmp;
    t_cord cord;

    tmp = ft_split(str,',');
    cord.x = ft_atoi(tmp[0]);
    cord.y = ft_atoi(tmp[1]);
    cord.z = ft_atoi(tmp[2]);
    return(cord);
}

int add_int(char *str)
{
return(ft_atoi(str));
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