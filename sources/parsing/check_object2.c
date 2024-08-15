/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:34:29 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/15 19:46:50 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


int check_camera(char *tab , t_data *data)
{
    char        **tmp;
    // t_camera    *cam;

    // cam = malloc(sizeof(t_camera));
    char content[6] = {'c','f','f','k','v','v'}; // float k->t

    if (check_num(tab, "C", 4))
        return (1);
    tmp = check_correct_type(content, tab);
    if(tmp == NULL)
        return(1);
    
    // cam->origine = add_vector_float(tmp[1]);
    data->scene->camera->origine = add_vector_float(tmp[1]);
    // cam->direction = add_vector_float(tmp[2]);
    data->scene->camera->direction = add_vector_float(tmp[2]);
    // cam->fov = add_float(tmp[3]);
    data->scene->camera->fov = add_float(tmp[3]);
    // cam->fov = 90.0;
    // if(cam->fov > 180 || cam->fov < 0)
    // {
    //     printf("ERROR fov superieur a 180 ou inferieur a 0");
    //     free(cam);
    //     free_tab(tmp);
    //     return(1);
    // }
    // data->scene->camera = cam;
    // free(cam);
    free_tab(tmp);
    return(0);
}


int check_light(char *tab, t_data *data)
{
    char **tmp;

    char content[6] = {'c','f','t','i','v','v'};

    if (check_num(tab, "L", 4))
        return (1);
    tmp = check_correct_type(content, tab);
    if(tmp == NULL)
        {
        free(tmp);
        return(1);
        }
    free_tab(tmp);
    return(0);

}
   
int check_sphere(char *tab , t_data *data)
{
    t_sphere *current;
    char **tmp;

    char content[6] = {'c','f','t','i','v','v'};

    current = malloc(sizeof(t_sphere));
    if (check_num(tab, "sp", 4))
        return (1);
    tmp = check_correct_type(content, tab);
        if(tmp == NULL)
        {
            free_tab(tmp);
            return(1);
        }
            
    current->center =  add_vector_float(tmp[1]);
    current->diameter = add_float(tmp[2]);
    current->color = add_color_int(tmp[3]);
    current->next = NULL;

    data->scene->spheres->next = current;
    data->scene->spheres = data->scene->spheres->next;
    
    free_tab(tmp);
    return(0);
}

int check_plane(char *tab, t_data *data)
{
    t_plane *current;
    char **tmp;

    current = malloc(sizeof(t_plane));
    char content[6] = {'c','f','f','i','v','v'};
    if (check_num(tab, "pl", 4))
        return (1);
    tmp = check_correct_type(content, tab);
        if(tmp == NULL)
        {
            free_tab(tmp);
            return(1);
        }
    current->origine = add_vector_float(tmp[1]);
    current->direction = add_vector_float(tmp[2]);
    current->color = add_color_int(tmp[3]);

    free_tab(tmp);
    return(0);
}

int check_cylinder(char *tab, t_data *data)
{
    char **tmp;
    char content[6] = {'c','f','f','t','t','i'};

    if (check_num(tab, "cy", 6))
        return (1);
    tmp = check_correct_type(content, tab);
    if(tmp == NULL)
        {
            free_tab(tmp);
            return(1);
        }
    free_tab(tmp);
    return(0);
}