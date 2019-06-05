/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 05:53:28 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/04 22:51:58 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;

	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	while (n--)
	{
		if (*str != c1)
			str++;
		else
			return (str);
	}
	return (0);
}
