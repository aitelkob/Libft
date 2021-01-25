/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:47:05 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:47:06 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;

	temp = NULL;
	if (dest < src || dest > (src + n))
		ft_memcpy(dest, src, n);
	else
	{
		if (!(temp = (unsigned char *)malloc(n * sizeof(unsigned char))))
			return (0);
		else
		{
			ft_memcpy(temp, src, n);
			ft_memcpy(dest, temp, n);
			free(temp);
		}
		temp = NULL;
	}
	return (dest);
}
