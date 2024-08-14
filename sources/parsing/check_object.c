/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/14 09:37:07 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


int check_correct_type(char *content, char **tmp)
{
    int j;

    j = 0;
    while (tmp[j])
    {
        if (content[j] == 'i') //  verifiaction cord x, y , z et RGB
        {
            if(check_correct_intxyz(tmp, &j))
            {
                printf("ERROR TYPE (R,G,B) \n");
                break;
            }
        }
        else if (content[j] == 'f' )// Vérification des flottants  x ,y , z
        {
            if(check_correct_floatxyz(tmp, &j))
                {
                printf("ERROR TYPE (x,y,z) \n");
                return(1);
                } 
            j++; 
        }
        else if (content[j] == 'c')//Vérification char
        {
            if(check_correct_char(tmp, &j))
                {
                printf("ERROR TYPE CHAR\n");
                return(1);
                }
            j++;
        }

        else if(content[j] == 'k') //Vérification des int 
        {
            if(check_correct_int(tmp , &j))
                {
                printf("ERROR TYPE INT\n");
                return(1);
                }
            j++;
        }
        else if(content[j] == 't')//Vérification des flottants
        {   
            if(check_correct_float( tmp , &j)==1)
                {
                printf("ERROR TYPE FLOAT\n");
                return(1);
                }  
            j++; 
        }
        else
        {
            j++;
        }
    }
    free(tmp);
    return(0);
 }

/*
    explication du tableau content
    c = char 
    f = cordonner flote mais sous trois axe x,y,z
    i = cordonner int sous trois axe z,y,z
    k = une FOV , en int 1 valeur attendu
    t = une taille de volume floate (utile pour L , cy) 

*/
int check_a(char *tab, t_data *data)
{
    char **tmp;
    char content[6] = {'c','t','i','v','v','v'};

    if (check_num(tab, "A", 3))
        return (1);
    if(check_correct_type(content, tab))
        return(1);
    return(0);
}

