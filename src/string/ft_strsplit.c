/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:14:09 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:14:11 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_word(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i])
		j++;
	while (s[j] && s[j] == c)
		j++;
	while (s[j])
	{
		if (s[j] == c)
		{
			while (s[j])
				if (s[j] == c)
					j++;
				else
					break ;
			if (s[j])
				i++;
		}
		j++;
	}
	return (i);
}

static char		*ft_word(char const *s, int start, int end)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (tab == NULL)
		return (NULL);
	while (start < end)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_word(s, c) + 2))))
		return (NULL);
	while (s[i])
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		(j > i) ? (tab[k++] = ft_word(s, i, j)) &&\
						(i = j) : i++;
	}
	tab[k] = 0;
	return (tab);
}
