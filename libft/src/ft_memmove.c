/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:10:56 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 12:12:47 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy 'n' bytes from 'src' to 'dest'
// the memory areas may overlap
// return original value of dest
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
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	// test case 1
    char src1[] = "Hello World!";
    char dest1[20];
	char res1[20];

    ft_memmove(dest1, src1 + 6, 10);
	memmove(res1, src1 + 6, 10);
    printf("src1 = %s\n", src1);
    printf("dest1 = %s (expected: %s)\n", dest1, res1);

	// test case 2
	char src2[] = "123456";
	char res_src2[] = "123456";

	printf("\nbefore src2 = %s\n", src2);
	ft_memmove(src2, src2 + 2, 4);
	memmove(res_src2, res_src2 + 2, 4);
	printf("after src2 = %s (expected: %s)\n", src2, res_src2);
    return (0);
}
*/