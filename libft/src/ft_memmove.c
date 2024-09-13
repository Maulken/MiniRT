/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:33:01 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:33:03 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*c_dest;
	const char	*c_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	c_dest = (char *)dest;
	c_src = (const char *)src;
	if (c_src == c_dest)
		return (dest);
	if (c_src < c_dest && c_src + n > c_dest)
	{
		while (n > 0)
		{
			c_dest[n - 1] = c_src[n - 1];
			n--;
		}
	}
	while (n > 0)
	{
		*c_dest = *c_src;
		c_dest++;
		c_src++;
		n--;
	}
	return (dest);
}
