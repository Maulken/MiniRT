/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmassoli <vmassoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:42:37 by bszabo            #+#    #+#             */
/*   Updated: 2024/07/16 10:42:43 by vmassoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check if the character is printable
// return 1 if true, 0 if false
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
