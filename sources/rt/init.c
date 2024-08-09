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


int	init_struct(t_data *data)
{
	data->height = 0;
	data->width = 0;
    
    data->wx = 500;
	data->wy = 500;
    data->bits_per_pixel = 20;

    return(0);
}
