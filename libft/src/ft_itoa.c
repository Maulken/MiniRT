/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:33:21 by vmassoli          #+#    #+#             */
/*   Updated: 2024/09/18 15:25:57 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count the number of digits in the integer
static int	count_digits(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// fill the string with the digits of the integer
static void	fill_str(char *str, int n, int digits_len)
{
	int	i;

	i = 1;
	str[digits_len] = '\0';
	while (n > 0)
	{
		str[digits_len - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
}

// handle the edge cases (min int and 0)
static char	*handle_edge(int n)
{
	char	*str;

	str = NULL;
	if (n == -2147483648)
	{
		str = (char *)malloc(sizeof(char) * 12);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		fill_str(str, n, 11);
	}
	else if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

// convert the integer to a string and return the result
char	*ft_itoa(int n)
{
	int		sign;
	int		digits_len;
	char	*str;

	sign = 1;
	digits_len = 0;
	if (n == -2147483648 || n == 0)
		return (handle_edge(n));
	else if (n < 0)
	{
		n *= -1;
		sign = -1;
		digits_len++;
	}
	digits_len += count_digits(n);
	str = (char *)malloc(sizeof(char) * (digits_len + 1));
	if (str == NULL)
		return (NULL);
	fill_str(str, n, digits_len);
	if (sign == -1)
		str[0] = '-';
	return (str);
}
