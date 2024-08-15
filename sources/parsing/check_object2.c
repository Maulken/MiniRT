/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/15 10:00:14 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_c(char *tab , t_data *data) // a ton la place pour creer objec
{
    char        **tmp;
    t_camera    *camera;

    camera = malloc(sizeof(t_camera));
    char content[6] = {'c','f','f','k','v','v'};
    if (check_num(tab, "C", 4))
        return (1);
    tmp = check_correct_type(content, tab);
    if(tmp == NULL)
        return(1);
    
    camera->cam_cord = *add_cord_float(tmp[1]);
    camera->cam_or   =  *add_cord_float(tmp[2]);
    camera->cam_fov  = add_float(tmp[3]);
    data->scenes->cam = *camera ;

    free(tmp);  
    return(0);
}

int check_l(char *tab, t_data *data)
{
    char **tmp;
    t_light *s_light;

    char content[6] = {'c','f','t','i','v','v'};

    if (check_num(tab, "L", 4))
        return (1);
    tmp = check_correct_type(content, tmp);
    if(tmp == NULL)
        return(1);
  return(0);
}
    
int check_sp(char *tab , t_data *data)
{
    t_sphere *current;
    char **tmp;


    char content[6] = {'c','f','t','i','v','v'};

    if (check_num(tab, "sp", 4))
        return (1);
    tmp = check_correct_type(content, tab);
        return(1);
    current->sp_point =  *add_cord_float(tmp[1]);
    current->
  return(0);
}
int check_pl(char *tab, t_data *data)
{
    char **tmp;
    char content[6] = {'c','f','f','i','v','v'};

    if (check_num(tab, "pl", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
  return(0);
}

int check_cy(char *tab, t_data *data)
{
    char **tmp;
    char content[6] = {'c','f','f','t','t','i'};

    if (check_num(tab, "cy", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
    return(0);
}