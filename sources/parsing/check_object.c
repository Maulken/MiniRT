/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:53:36 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/12 15:41:07 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int check_num(char *tab, char *str, int size_setting)
{
    int i;
    int len;
    int j;
    int in_word;

    j = 0;
    i = 0;
    len = 0;


    while(tab[i] != '\0')
    {
        if(tab[i] == ' ' || tab[i] == '\t')
        {
            i++;
            in_word = 0 ;
        }
        else if(!in_word)
        {
            in_word = 1;
            len++;

        }
        else if(len == 0)
            {
                while(tab[i] == ' ')
                    i++;
                while(str[j] != '\0' && tab [i] != '\0')
                {
                    if(str[j] != tab[i])
                            return 1;
                    i++;
                    j++;  
                } 
                len++;          
            }
        while(tab[i] <= 33 && tab[i] >= '~')
        {
            if ((tab[i] < '0' || tab[i] > '9') && tab[i] != '.' && tab[i] != ',' && tab[i] != ' ' && tab[i] != '-')
            {
                printf("why to carathre plese IS NUMBER : %c ", tab[i]);
                return 1; 
            }
            i++;
            in_word = 0;
        }
        i++;
    }
    len++;
    if(len != size_setting)
    {
        printf("error trop ou pas asser de parametre ou char dans le int : %d \n", len);
        return 1;
    }
    return 0;
}


int check_correct_type(char *content, char *tab)
{
    char **tmp = ft_split(tab, ' ');
    int i;
    int j;
    int is_num;
    int len ;

    is_num = 0;
    len = 0 ;
    j = 0;
    while (tmp[j])
    {
        i = 0;
        // Vérification des entiers
        if (content[j] == 'i') //  verifiaction cord x, y , z et RGB
        {
            char **tab;
            i = 0;
            while (tmp[j][i] != '\0') 
            {
                if ((tmp[j][i] < '0' || tmp[j][i] > '9') && 
                tmp[j][i] != '.' && tmp[j][i] != '-' && 
                tmp[j][i] != '+' &&  tmp[j][i] != ',')
                    break;
                i++;
            }
            if (tmp[j][i] == '\0')
            {
                tab = ft_split(tmp[j],',');
                    if(size_tab(tab) != 3)
                        {
                            free(tab);
                            printf("ERROR plese (R,G,B) \n");
                            return(1);
                           
                        }
                j++;
                free(tab);
                continue;
            }
        }
        // Vérification des flottants en 3 fois
        if (content[j] == 'f' )
        {
            char **tab;
            i = 0;
            while (tmp[j][i] != '\0') 
            {
                if ((tmp[j][i] < '0' || tmp[j][i] > '9') && 
                tmp[j][i] != '.' && tmp[j][i] != '-' && 
                tmp[j][i] != '+' &&  tmp[j][i] != ',')
                    break;
                i++;
            }
            if (tmp[j][i] == '\0')
            {
                tab = ft_split(tmp[j],',');
                    if(size_tab(tab) != 3)
                        {
                            free(tab);
                            printf("ERROR plese (x,y,z)\n");
                            return(1);
                           
                        }
                j++;
                free(tab);
                continue;
            }
        }
        // Vérification des caractères
        if (content[j] == 'c')
        {
            i = 0;
            while (tmp[j][i] != '\0')
            {
                if ((tmp[j][i] < 'A' || tmp[j][i] > 'Z') && (tmp[j][i] < 'a' || tmp[j][i] > 'z'))
                    break;
                i++;
            }
            if (tmp[j][i] == '\0')
            {
                j++;
                continue;
            }
        }
        if(content[j] == 'k')
        {
            i = 0;
            while (tmp[j][i] != '\0')
            {
                if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
                tmp[j][i] != '-' && tmp[j][i] != '+'  && 
                tmp[j][i] != ',')
                    break;
                i++;
            }
            if (tmp[j][i] == '\0')
            {
                j++;
                continue;
            }
        }

        if(content[j] == 't')
        {
            i = 0;
            while (tmp[j][i] != '\0') 
            {
                if ((tmp[j][i] < '0' || tmp[j][i] > '9') &&
                tmp[j][i] != '.' && tmp[j][i] != '-' && 
                tmp[j][i] != '+' &&  tmp[j][i] != ',')
                    break;
                i++;
            }
            if (tmp[j][i] == '\0')
            {
                j++;
                continue;
            }
        }
        free(tmp);
        return 1;
    }
    free(tmp);
    return 0;
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