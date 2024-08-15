/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:39:57 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/15 17:07:57 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minirt.h"

// voir en dessous
int endwith(char *argv, char *value)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(argv[i] == '\0')
            i++;
    i -= ft_strlen(value);
    while(argv[i])
    {
        if(argv[i] == value[j])
        {
            j++;
            i++;
        }
        else 
            return(ERROR);
    }
    return(OK);
}

// verification que le fichier et correct
int check_argument(int argc , char **argv)
{

    int i;
    int fd;

    i = 0;
    if(argc != 2 )
    {
		printf("plese ./Minirt enter the secene.rt");
        return(-1);
    }
    if(!argv[1] || !*argv[1])
    {
        printf("error fichier vide");
        return(-1);
    }
    while(argv[i])
        i++;
    if(i >= 3)
    {
        printf("error size of the ... ");
        return(-1);
    }
    if(!endwith(argv[1],".rt"))
    {
        printf("error plese file finish.rt");
        return(-1);
    }
    fd = open(argv[1], O_RDWR);
	if(fd == -1)
    {
        printf("no accessed the file.rt");
        return(-1);
    }
    // test du dossier
    return(fd);

}

// verificaiton si tout et bon . avant de faire des allocation . et tout le ... 
int check_tab(char **rows , t_data *data)
{
    int i;

    i = 0;
  //  if(check_min_scene(rows) == ERROR) //a de coomenter pour tester
     //   {
            //free ??
     //      return(1);
     //   }
    while(rows[i])
    {
        if(check_type(rows[i], data)) // test tout 
            {
                printf("\nparse eror ligne : %d \n",i);
                return(1);
            }
        i++;
    }
    return(OK);
}


// verifaication de controle du nombre de lumier si il y a une camera ect .... 
int check_min_scene(char **tab)
{
int i;
int len_a;
int len_c;
int len_l;

i = 0;
len_a = 0;
len_c = 0;
len_l = 0;

while(tab[i])
{
    if(!ft_strncmp(tab[i], "A ", 2))
        len_a++;
    if(!ft_strncmp(tab[i], "C ", 2))
        len_c++;
    if(!ft_strncmp(tab[i], "L ", 2))
        len_l++;
    i++;
}
if(len_a != 1 || len_c != 1 || len_l < 1 ) 
{
    printf("error : il doit avoir  (1)A|%d|,(1)C|%d|,(inf)L|%d|",len_a , len_c, len_l);
    return(ERROR);
}
return(OK);
}

int check_type(char *src ,t_data *data)
{
    char    **tab;
    
    tab = ft_split(src,' ');
    if(!tab)
    {
        printf("malloc error");
        return(ERROR);
    }
    if(tab[0])
    {
        if(!ft_strncmp(tab[0],"A",2))
            return(check_ambiance(src,data));
        else if(!ft_strncmp(tab[0],"C",2))
            return(check_camera(src,data));
        else if(!ft_strncmp(tab[0],"L",2))
            return(check_light(src,data));
        else if(!ft_strncmp(tab[0],"sp",3))
            return(check_sphere(src,data));
        else if(!ft_strncmp(tab[0],"pl",3))
            return(check_plane(src,data));
        else if(!ft_strncmp(tab[0],"cy",3))
            return(check_cylinder(src,data));
        else 
           {
              printf("why fuking line :%s\n",tab[0]);
              return(1);
            } 
             
    }
    
    return(0);
}