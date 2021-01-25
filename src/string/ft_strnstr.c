/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:16:21 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:16:37 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char*)(str));
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j] || i + j >= n)
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return ((char*)(str + i));
		i++;
	}
	return (NULL);
}
