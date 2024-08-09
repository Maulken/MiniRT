/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:39:57 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/09 10:25:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minirt.h"

int endwith(char *argv, char *value)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(argv[i] == '\0')
            i++;
    i =- ft_strlen(value);
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


int check_argument(int argc , char **argv)
{

    int i;
    int fd;

    if(argc != 2 )
		(printf("plese ./Minirt enter the secene.rt"),exit(1));
    if(!argv[1] || !*argv[1])
        (printf("error"), exit(1));

    while(argv[i])
        i++;
    if(argv<=3)
        printf("error");
    if(!endwith(argv[1],".rt"))
        (printf("error plese file finish.rt"));

    fd = open(argv[1], O_RDWR);
	if(fd == -1)
        printf("no accessed the file.rt");

    return(fd);

}