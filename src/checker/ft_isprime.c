/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:05:53 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:05:55 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_isprime(size_t nb)
{
	size_t	i;
	size_t	compt;

	i = 1;
	compt = 1;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			compt++;
			if (compt > 2)
				return (0);
		}
		i++;
	}
	if (compt == 2)
		return (1);
	else
		return (0);
}
