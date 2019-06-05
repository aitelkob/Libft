/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 07:37:15 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/22 04:37:44 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*srcc;
	unsigned char		*dest;

	srcc = (unsigned char*)src;
	dest = (unsigned char*)dst;
	if (srcc < dest)
	{
		while (len)
		{
			len--;
			dest[len] = srcc[len];
		}
	}
	else
		ft_memcpy(dest, srcc, len);
	return (dst);
}
