/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:19:12 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/07 14:05:28 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// concatenate string 'src' to string 'dest' up to 'size' characters
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (size <= dest_len)
		return (size + src_len);
	while ((dest_len + i) < (size - 1) && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char dest[20] = "hello";
	char src[20] = " world";
	printf("%s + %s = ", dest, src);
	size_t res = ft_strlcat(dest, src, 3);
	printf("%s (length: %zu)\n", dest, res);

	char dest2[20] = "hello";
	char src2[20] = " world";
	printf("%s + %s = ", dest2, src2);
	size_t res2 = strlcat(dest2, src2, 3);
	printf("%s (length: %zu) | original\n", dest2, res2);
	return (0);
}
*/