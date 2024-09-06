/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:43:01 by bszabo            #+#    #+#             */
/*   Updated: 2024/09/06 14:36:47 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocate memory for num elements of size bytes each, set all values to zero
// return a pointer to the allocated memory
// void	*ft_calloc(size_t num, size_t size)
// {
// 	char	*ptr_mem;
// 	int		len;

// 	len = num * size;
// 	ptr_mem = (char *)malloc(len);
// 	if (ptr_mem == NULL)
// 		return (NULL);
// 	while (len > 0)
// 	{
// 		ptr_mem[len - 1] = '\0';
// 		len--;
// 	}
// 	return ((void *)ptr_mem);
// }

void	*ft_calloc(size_t num, size_t size)
{
	char	*str;

	str = malloc(num * size);
	if (!str)
		return (NULL);
	ft_bzero(str, num * size);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	char *test1 = (char *)calloc(5, sizeof(int));
	printf("Original calloc: ");
	for (int i = 0; i < 5; i++)
		printf("%d | ", test1[i]);

	char *test2 = (char *)ft_calloc(5, sizeof(int));
	printf("\n   My ft_calloc: ");
	for (int i = 0; i < 5; i++)
		printf("%d | ", test2[i]);
	free(test1);
	free(test2);
	return (0);
}
*/
