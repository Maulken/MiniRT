/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:30:34 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/03 16:30:35 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

// allocate memory for num elements of size bytes each, set all values to zero
// return a pointer to the allocated memory
void	*ft_calloc(size_t num, size_t size)
{
	char	*ptr_mem;
	int		len;

	len = num * size;
	ptr_mem = (char *)malloc(len);
	if (ptr_mem == NULL)
		return (NULL);
	while (len > 0)
	{
		ptr_mem[len - 1] = '\0';
		len--;
	}
	return ((void *)ptr_mem);
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
