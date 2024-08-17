/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:03:14 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:05:29 by bszabo           ###   ########.fr       */
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
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[] = "hello";
    char str2[] = "hello world";
    char str3[] = "world";
    int res1o = memcmp(str1, str2, 5);
    int res1 = ft_memcmp(str1, str2, 5);
    int res2o = memcmp(str1, str2, 10);
    int res2 = ft_memcmp(str1, str2, 10);
    int res3o = memcmp(str1, str3, 5);
    int res3 = ft_memcmp(str1, str3, 5);
    int res4o = memcmp(str3, str1, 5);
    int res4 = ft_memcmp(str3, str1, 5);
    printf("%d | original\n", res1o);
    printf("%d\n", res1);
    printf("%d | original\n", res2o);
    printf("%d\n", res2);
    printf("%d | original\n", res3o);
    printf("%d\n", res3);
    printf("%d | original\n", res4o);
    printf("%d\n", res4);
    return (0);
}
*/
