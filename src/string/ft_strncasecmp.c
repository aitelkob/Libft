/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:19:11 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:19:14 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*low_case(unsigned char *str)
{
	int		n;
	int		i;
	char	*tmp;

	n = (int)ft_strlen(((const char*)str));
	tmp = (char*)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		if (str[i] < 'Z' && str[i] > 'A')
			tmp[i] = str[i] + 32;
		else
			tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int			ft_strncasecmp(char *str1, char *str2, int n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	i = 0;
	s1 = (unsigned char*)low_case((unsigned char*)s1);
	s2 = (unsigned char*)low_case((unsigned char*)s2);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		else
			i++;
	}
	return (0);
}
