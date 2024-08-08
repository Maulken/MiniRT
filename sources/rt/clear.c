#include "../../includes/minirt.h"


int	ft_close(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

clean(t_data *data ,int code_error)
{
	printf("free");
return(code_error);
}