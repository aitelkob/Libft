/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:41:30 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:41:32 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(str);
	if ((char)c == '\0')
		return (char*)(str + slen);
	while (i < slen)
	{
		if (str[i] == (char)c)
			return ((char*)(str + i));
		else
			i++;
	}
	return (NULL);
}
