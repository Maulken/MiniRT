/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:39:57 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/10 13:22:07 by vharatyk         ###   ########.fr       */
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
    return(fd);

}

// verificaiton si tout et bon . avant de faire des allocation . et tout le ... 
int check_tab(char **rows , t_data *data)
{
    int i;

    i=0;
    if(check_min_scene(rows) == ERROR) //
        {
            //free ??
           return(ERROR);
        }
    while(rows[i])
    {
        if(check_type(rows[i], data))
            {
                printf("parse eroor");
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

while(tab)
{
    if(!ft_strncmp(tab[i], "A", 2))
        len_a++;
    if(!ft_strncmp(tab[i], "C", 2))
        len_c++;
    if(!ft_strncmp(tab[i], "L", 2))
        len_l++;
}
if(len_a == 1 || len_c == 1 || len_l < 1 ) 
{
    printf("error : il doit avoir  (1)A,(1)C,(inf)L");
    return(ERROR);
}
return(OK);
}

int check_type(char *str ,t_data *data)
{
    char **tab;
    int value_return ;

    value_return = 0;
    tab = ft_split(str,' ');
    if(!tab)
    {
        printf("malloc error");
        return(ERROR);
    }
    if(tab[0])
    {
       // COMMENT: A FINIR
        // if(!ft_strncmp(tab[0],"A",2));
        //     return(check_a(tab));
        // if(!ft_strncmp(tab[0],"C",2));
        //     return(check_a(tab));
        // if(!ft_strncmp(tab[0],"L",2));
        //     return(check_a(tab));
        // if(!ft_strncmp(tab[0],"sp",2));
        //     return(check_a(tab));
        // if(!ft_strncmp(tab[0],"pl",2));
        //     return(check_a(tab));
        // if(!ft_strncmp(tab[0],"cy",2));
        //     return(check_a(tab));
        
    }
    return(OK);
}