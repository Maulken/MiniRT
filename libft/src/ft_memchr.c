/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:31:48 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:31:55 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	unsigned char	*c_ptr;

	c_ptr = (unsigned char *)ptr;
	while (n > 0)
	{
		if (*c_ptr == (unsigned char)c)
			return ((void *)c_ptr);
		c_ptr++;
		n--;
	}
	return (0);
}
