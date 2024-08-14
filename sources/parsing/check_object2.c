/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/14 10:30:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_c(char *tab , t_data *data) // a ton la place pour creer objec
{
    char **tmp = ft_split(tab, ' ');

    char content[6] = {'c','f','f','k','v','v'};
    if (check_num(tab, "C", 4))
        return (1);
    if(check_correct_type(content, tmp))
        return(1);
    
    data->scenes->cam.cam_cord = add_cord_float(tmp[1]);
    add_cord_int(data);
    add_int();
    add_rgb();


    
       
  return(0);
}

int check_l(char *tab, t_data *data)
{
char **tmp;
    char content[6] = {'c','f','t','i','v','v'};

    if (check_num(tab, "L", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
  return(0);
}
    
int check_sp(char *tab , t_data *data)
{
    char **tmp;
    char content[6] = {'c','f','t','i','v','v'};


    if (check_num(tab, "sp", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
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