/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 13:55:49 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/27 13:56:58 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char *)s1;
	dst = (unsigned char *)s2;
	while ((src[i] != '\0' || dst[i] != '\0') && i < n)
	{
		if (src[i] != dst[i])
		{
			return (src[i] - dst[i]);
		}
		i++;
	}
	return (0);
}
