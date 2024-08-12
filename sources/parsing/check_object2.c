/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/12 16:39:35 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_c(char *tab , t_data *data) // a ton la place pour creer objec
{
    char **tmp;
    char content[6] = {'c','f','f','k','v','v'};
    if (check_num(tab, "C", 4))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
    
    
       
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