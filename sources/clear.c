#include "../includes/minirt.h"


int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}