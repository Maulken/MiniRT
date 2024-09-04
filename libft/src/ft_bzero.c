/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:30:03 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/03 16:30:04 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

// erase the data in the n bytes of the memory by writing zeroes
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char s[10] = "testing";
	printf("before: %s\n", s);
	ft_bzero(s, 5);
	printf("after: %s\n", s);
	printf("%c", s[5]);
	return (0);
}
*/
