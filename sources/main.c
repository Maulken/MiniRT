/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:33:20 by mpelluet          #+#    #+#             */
/*   Updated: 2024/09/18 14:41:21 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	event(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->view.width, data->view.height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endin);
	ray_tracing(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_close(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	init_scene(&data);
	init_data(&data);
	if (parsing(argc, argv, &data) == ERROR)
		return (clean_data(&data, 1));
	data.mlx = mlx_init();

	printf("%f\n",data.scene->camera->origine.x);

	if (data.mlx == NULL)
		return (printf("ERROR : MLX"), clean_data(&data, 1));
	data.win = mlx_new_window(data.mlx, data.view.width, data.view.height,
			"MiniRT");
	event(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 5, ft_close, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (clean_data(&data, 0));
}
