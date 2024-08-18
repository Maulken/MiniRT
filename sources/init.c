#include "../includes/minirt.h"



int	init_struct(t_data *data)
{
	t_scene *scene;

	data->view = malloc(sizeof(t_view));
	if (!data->view)
		return (0);
	data->scene = NULL;
	data->white_light = malloc(sizeof(t_color));
	if (!data->white_light)
		return (0);
	data->white_light->r = 255;
	data->white_light->g = 255;
	data->white_light->b = 255;
	data->view->height = 600;
	data->view->x_pixel = 0;
	data->view->y_pixel = 0;
	data->view->width = 800;
	// data->bits_per_pixel = 20;

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
}
