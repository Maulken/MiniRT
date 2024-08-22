/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelluet <mpelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:11:31 by vmassoli          #+#    #+#             */
/*   Updated: 2024/08/19 20:26:20 by mpelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	next(char *str)
{
	while (*str == 32 || *str == 9)
		(str)++;
}
double	ft_atof(char *str)
{
	int		w;
	double	d;
	int		neg;

	w = 0;
	neg = 1;
	if (*str == '-' && ((*str)++))
		neg = -1;
	while (ft_isdigit(*str))
		w = w * 10 + (((*str)++) - '0');
	if (*str == '.')
		(*str)++;
	d = 0.0;
	while (ft_isdigit(*str))
		d = d * 10 + (((*str)++) - '0');
	while (d >= 1)
		d /= 10;
	d += w;
	next(str);
	return (d * neg);
}
