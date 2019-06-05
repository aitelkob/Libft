/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:19:28 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/19 19:22:24 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	nbr;
	int		sign;

	nbr = n;
	sign = 0;
	if (n < 0)
		sign = 1;
	i = ft_nbrlen(n);
	if (!(str = ft_strnew(i + sign)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (i > 0)
	{
		str[i + sign - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
