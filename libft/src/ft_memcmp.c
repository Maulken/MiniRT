/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:32:03 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/12 16:32:14 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare 'n' bytes of 'ptr1' and 'ptr2'
// if identical return 0, else difference between first two differing bytes
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*c_ptr1;
	unsigned char	*c_ptr2;

	c_ptr1 = (unsigned char *)ptr1;
	c_ptr2 = (unsigned char *)ptr2;
	while (n > 0)
	{
		if (*c_ptr1 != *c_ptr2)
			return (*c_ptr1 - *c_ptr2);
		c_ptr1++;
		c_ptr2++;
		n--;
	}
	return (0);
}
