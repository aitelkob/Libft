/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:42:03 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:42:04 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	sqr;
	size_t	temp;

	temp = nb / 4;
	if (temp <= 46340 && temp * temp <= nb)
		sqr = temp;
	else
		sqr = 1;
	while (sqr <= nb / 2)
	{
		if (sqr * sqr == nb)
			return (sqr);
		sqr++;
	}
	return (0);
}
