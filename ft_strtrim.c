/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 00:46:24 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/20 03:29:26 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	while (ft_whitespace(s[i]))
		i++;
	while (ft_whitespace(s[j - 1]))
		j--;
	if (j < i)
		j = i;
	if (!(str = ft_strnew(j - i)))
		return (NULL);
	return (ft_strncpy(str, s + i, j - i));
}
