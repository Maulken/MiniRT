/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:57:43 by vmassoli          #+#    #+#             */
/*   Updated: 2024/07/11 10:57:45 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// check character after '%', if it is a valid specifier, handle it
// if it is not a valid specifier, just return without doing anything
// return the number of characters printed
static int	handle_percent(const char **str, va_list arg_ptr, int fd)
{
	int	count;

	count = 0;
	(*str)++;
	if (**str == '\0')
		return (0);
	else if (**str == 'c')
		count += print_char_fd(va_arg(arg_ptr, int), fd);
	else if (**str == 's')
		count += print_str_fd(va_arg(arg_ptr, char *), fd);
	else if (**str == 'p')
		count += print_ptr_fd(va_arg(arg_ptr, void *), fd);
	else if (**str == 'd' || **str == 'i')
		count += print_int_fd(va_arg(arg_ptr, int), fd);
	else if (**str == 'u')
		count += print_uint_fd(va_arg(arg_ptr, int), fd);
	else if (**str == 'x' || **str == 'X')
		count += print_hex_fd(va_arg(arg_ptr, unsigned int), **str, fd);
	else if (**str == '%')
		count += write(fd, "%", 1);
	return (count);
}

// check characters in 'str', if not '%' then print it, otherwise handle it
// return the number of characters printed
int	ft_printf_fd(int fd, const char *str, ...)
{
	int		count;
	va_list	arg_ptr;

	count = 0;
	va_start(arg_ptr, str);
	if (*str == 0)
		return (-1);
	while (*str)
	{
		if (*str != '%')
			count += write(fd, str, 1);
		else if (*str == '%')
			count += handle_percent(&str, arg_ptr, fd);
		str++;
	}
	va_end(arg_ptr);
	return (count);
}
