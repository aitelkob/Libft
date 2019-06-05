/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 05:30:19 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/04 22:49:27 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcc;

	dest = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest[i] = srcc[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)dest + i + 1);
		++i;
	}
	return (NULL);
}
