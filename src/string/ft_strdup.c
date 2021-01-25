/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:38:55 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:38:58 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	int		n;

	i = 0;
	n = ft_strlen(s);
	str = (char*)malloc((n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < n)
		{
			str[i] = s[i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
