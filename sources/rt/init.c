#include "../../includes/minirt.h"



int	init_struct(t_data *data)
{
    t_scene *scene;
    
    data->view = malloc(sizeof(t_view));
    if (!data->view)
        return (0);
    data->scene = NULL;
	data->view->height = 500;
    data->view->x_pixel = 0;
    data->view->y_pixel = 0;
	data->view->width = 500;
    data->bits_per_pixel = 20;

    return(0);
}

void init_data(t_data *data)
{
    data->scene = (t_scene *)malloc(sizeof(t_scene));
    if (data->scene == NULL) 
    {
        printf("Memory allocation failed \n");
        exit(1);
    }
    data->scene->spheres = malloc(sizeof(t_sphere));
    if(data->scene->spheres == NULL)
    {
        printf("Memory allocation failed \n");
        exit(1);
    }
 
}
