/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:04:39 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:04:40 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(long n)
{
	int l;

	l = 0;
	if (n <= 0)
	{
		if (n < 0)
			n = n * -1;
		l++;
	}
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	i = length(n);
	nb = n;
	str = (char*)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
