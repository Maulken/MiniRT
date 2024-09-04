/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:55:42 by bszabo            #+#    #+#             */
/*   Updated: 2024/09/03 16:33:31 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// scan 'n' bytes from beginning of 'ptr' for first occurrence of 'c'
// return pointer to the matching byte or NULL if no match
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
