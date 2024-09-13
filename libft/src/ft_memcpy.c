/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:32:30 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:32:38 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*c_dest;
	char	*c_src;

	if (!dest && !src)
		return (0);
	i = 0;
	c_dest = (char *)dest;
	c_src = (char *)src;
	while (n > 0)
	{
		c_dest[i] = c_src[i];
		i++;
		n--;
	}
	return (dest);
}

