/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:15:20 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:15:21 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = (int)ft_strlen(str);
	if ((unsigned char)c == '\0')
		return ((char*)(str + i));
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char*)(str + i));
		i--;
	}
	return (NULL);
}
