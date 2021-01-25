/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:54:35 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:54:36 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	c1 = (unsigned char)c;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == c1)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
