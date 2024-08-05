/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:50:31 by bszabo            #+#    #+#             */
/*   Updated: 2023/09/12 09:52:38 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// output integer 'n' to file descriptor 'fd'
void	ft_putnbr_fd(int n, int fd)
{
	char	c_num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c_num = n + '0';
		write(fd, &c_num, 1);
	}
}
/*
int main(void)
{
    //int n = -2147483648;
	int n = -47628;
    //int n = 0;
    //int n = 2147483647;
    ft_putnbr_fd(n, 1);
    return (0);
}
*/