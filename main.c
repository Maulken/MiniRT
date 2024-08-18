/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:53:10 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/18 22:45:49 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	event(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->view->width, data->view->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	//ray_tracing(data->mlx, data->win, data);
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

int main(int argc , char **argv)
{
	t_data	data;
	void	*arena;
	char	*line;
	int		scene_fd;

	arena = arena_init((size_t)1e8);
	if (!arena)
		exit_error("Error: insufficient memory\n");
	alloc_struc(arena, &data);
	scene_fd = open(argv[1], O_RDWR);
	line = get_next_line(scene_fd);
	if (argc != 2)
		return (0);
	if(ft_parse_arg(line, &data) == ERROR)
	// return(clean(&data , 1));

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.view->width,
		data.view->height, "MiniRT");
	event(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 5, ft_close, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	clean(&data,0);
	arena_destroy(arena);
	return (EXIT_SUCCESS);
}
