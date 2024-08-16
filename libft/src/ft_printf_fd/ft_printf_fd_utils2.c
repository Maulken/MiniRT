/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:57:35 by vmassoli          #+#    #+#             */
/*   Updated: 2024/07/11 10:57:38 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// print lowercase or uppercase hexadecimal number to stdout
// return the number of characters written
int	print_hex_fd(unsigned long long n, char c, int fd)
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
			write(fd, &hex_sm[n], 1);
		else if (c == 'X')
			write(fd, &hex_lg[n], 1);
		count++;
	}
	else
	{
		count += print_hex_fd(n / 16, c, fd);
		count += print_hex_fd(n % 16, c, fd);
	}
	return (count);
}

// print a pointer to stdout and return the number of characters written
int	print_ptr_fd(void *ptr, int fd)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(fd, "(nil)", 5));
	count += write(fd, "0x", 2);
	count += print_hex_fd((unsigned long long)ptr, 'x', fd);
	return (count);
}
