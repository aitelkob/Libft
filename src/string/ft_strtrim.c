/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:13:28 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:13:30 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_trim(const char *s)
{
	int	n;
	int	i;

	n = (int)ft_strlen(s);
	i = n - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		n--;
		i--;
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		n--;
		i++;
	}
	return (n);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		n;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	n = len_trim(s);
	if (n <= 0)
		n = 0;
	str = (char*)malloc((n + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (j < n && s[i])
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
