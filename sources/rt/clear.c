/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:10:04 by vharatyk          #+#    #+#             */
/*   Updated: 2024/08/10 13:10:05 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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