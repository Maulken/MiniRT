/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:57:28 by vmassoli          #+#    #+#             */
/*   Updated: 2024/07/11 10:57:31 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// print a character to fd and return the number of characters written
int	print_char_fd(int c, int fd)
{
	char	c_c;

	c_c = (c);
	return (write(fd, &c_c, 1));
}

// print the string to stdout and return the number of characters written
int	print_str_fd(char *str, int fd)
{
	int	len;

	len = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (*str)
	{
		write(fd, str, 1);
		str++;
		len++;
	}
	return (len);
}

// print integer to stdout and return the number of characters written
int	print_int_fd(int n, int fd)
{
	int		count;
	char	c_num;

	count = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		count += write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		count += print_int_fd(n / 10, fd);
		count += print_int_fd(n % 10, fd);
	}
	else
	{
		c_num = n + '0';
		count += write(fd, &c_num, 1);
	}
	return (count);
}

// print unsigned integer to stdout and return the number of characters written
int	print_uint_fd(unsigned int n, int fd)
{
	int		count;
	char	c_num;

	count = 0;
	c_num = n + '0';
	if (n < 10)
		count += write(fd, &c_num, 1);
	else
	{
		count += print_uint_fd(n / 10, fd);
		count += print_uint_fd(n % 10, fd);
	}
	return (count);
}
