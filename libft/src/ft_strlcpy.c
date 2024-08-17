/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:03:58 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/05 12:12:35 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy up to size - 1 characters from the NUL-terminated string 'src'
// to 'dest', NUL-terminating the result
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char dest[20] = "abcd";
	char res_dest[20] = "abcd";

	char src[20] = "testing";
	char res_src[20] = "testing";

	printf("dest before copying: %s\n", dest);

	size_t result = ft_strlcpy(dest, src, 7);
	size_t res_result = strlcpy(res_dest, res_src, 7);

	printf("dest after copying: %s (expected: %s)\n", dest, res_dest);
	printf("length of src (%s): %zu (expected: %zu)\n", src, result, res_result);

	return (0);
}
*/