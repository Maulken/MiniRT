/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:06:26 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:08:54 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n bytes from memory area src to memory area dest
// the memory areas must not overlap
// use ft_memmove if the memory areas do overlap
// return original value of dest
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
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    double src_arr[5] = {1.8, 4.73, 2.8, 4.4, 9.9};
    double src_arr2[5] = {1.8, 4.73, 2.8, 4.4, 9.9};
    double dest_arr[5];
    double dest_arr2[5];
    void *res1 = ft_memcpy(dest_arr, src_arr, sizeof(src_arr));
	void *res2 = memcpy(dest_arr2, src_arr2, sizeof(src_arr2));
    for (int i = 0; i < 5; i++)
	{
        printf("src: %f | dest: %f\n", src_arr[i], dest_arr[i]);
        printf("src: %f | dest: %f | original\n", src_arr2[i], dest_arr2[i]);
	}
	printf("%p | dest_arr\n", dest_arr);
	printf("%p | ft_memcpy\n", res1);
	printf("%p | dest_arr2 | original\n", dest_arr2);
	printf("%p | memcpy | original\n", res2);
    return(0);
}
*/