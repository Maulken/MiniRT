#include "../includes/minirt.h"



int	init_struct(t_data *data)
{
	t_scene *scene;

	data->view = malloc(sizeof(t_view));
	if (!data->view)
		return (0);
	data->scene = NULL;
	data->white_light = malloc(sizeof(t_vector));
	if (!data->white_light)
		return (0);
	data->white_light->x = 255;
	data->white_light->y = 255;
	data->white_light->z = 255;
	data->view->height = 600;
	data->view->x_pixel = 0;
	data->view->y_pixel = 0;
	data->view->width = 800;
	data->x_ray = 0;
	data->y_ray = 0;

	return(0); // return (1) mieux ?
}

void init_data(t_data *data)
{
	data->scene = malloc(sizeof(t_scene));
	if (data->scene == NULL)
	{
		printf("Memory allocation failed \n");
		exit(1);
	}
	data->scene->camera = malloc(sizeof(t_camera));
	if(data->scene->camera == NULL){
			printf("Memory allocation failed \n");
			exit(1);
	}
	data->scene->spheres = malloc(sizeof(t_sphere));
	if(data->scene->spheres == NULL)
	{
		printf("Memory allocation failed \n");
		exit(1);
	}
	  data->scene->cylinder = malloc(sizeof(t_cylinder));
	if(data->scene->cylinder == NULL)
	{
		printf("Memory allocation failed \n");
		exit(1);
	}

	  data->scene->plane = malloc(sizeof(t_plane));
	if(data->scene->plane == NULL)
	{
		printf("Memory allocation failed \n");
		exit(1);
	}

	 data->scene->light = malloc(sizeof(t_light));
	if(data->scene->light == NULL)
	{
		printf("Memory allocation failed \n");
		exit(1);
	}
	data->scene->ambient = malloc(sizeof(t_ambient));
	if(data->scene->ambient == NULL)
	{
		printf("Memory allocation failed \n");
		exit(1);
	}

	data->scene->ambient->colors = new_vector(255, 255, 255);
	data->scene->ambient->ratio = 0.2;
}
