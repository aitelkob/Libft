/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:41:09 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/05 08:57:57 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		s1 = (unsigned char*)haystack;
		s2 = (unsigned char*)needle;
		while (*s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
