#include "../../includes/minirt.h"


int	init_struct(t_data *data)
{
	data->height = 0;
	data->width = 0;
    
    data->wx = 500;
	data->wy = 500;
    data->bits_per_pixel = 20;

    return(0);
}

void init_data(t_data *data)
 {
    

    data->scenes = (t_scene *)malloc(sizeof(t_scene));
    if (data->scenes == NULL) {
        fprintf(stderr, "Memory allocation failed for scenes\n");
        exit(1);
    }


 }