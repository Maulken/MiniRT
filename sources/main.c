#include "../includes/minirt.h"

int	event(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->view->width, data->view->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endin);
	//draw(data);
	ray_tracing(data->mlx, data->win, data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int main(int argc , char **argv)
{
  t_data data;

	init_struct(&data);
	init_data(&data);
  	if(parsing(argc , argv ,&data) == ERROR)
		return(clean(&data , 1));

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.view->width, data.view->height, "MiniRT");
	event(&data);
	//mlx_hook(data.win, 2, 1L << 0, control, &data); deplacement
	mlx_hook(data.win, 17, 1L << 5, ft_close, &data);
	mlx_loop(data.mlx);


	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);

  return (0);
}