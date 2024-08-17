/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:56:43 by vmassoli          #+#    #+#             */
/*   Updated: 2024/07/15 11:19:01 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// print lowercase or uppercase hexadecimal number to stdout
// return the number of characters written
int	print_hex(unsigned long long n, char c)
{
	int		count;
	char	*hex_sm;
	char	*hex_lg;

	hex_sm = "0123456789abcdef";
	hex_lg = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
	{
		if (c == 'x')
			write(1, &hex_sm[n], 1);
		else if (c == 'X')
			write(1, &hex_lg[n], 1);
		count++;
	}
	else
	{
		count += print_hex(n / 16, c);
		count += print_hex(n % 16, c);
	}
	return (count);
}

// print a pointer to stdout and return the number of characters written
int	print_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += print_hex((unsigned long long)ptr, 'x');
	return (count);
}
