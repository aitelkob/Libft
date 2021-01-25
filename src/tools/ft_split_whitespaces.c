/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:42:34 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:42:36 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j] && ((str[j] == ' ') || (str[j] == '\t') || (str[j] == '\n')))
		j++;
	while (str[j])
	{
		if ((str[j] == ' ') || (str[j] == '\t') || (str[j] == '\n'))
		{
			while (str[j])
				if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
					j++;
				else
					break ;
			if (str[j])
				i++;
		}
		j++;
	}
	return (i);
}

char	*word(char *str, int *start, int end)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * ((end - *start) + 1));
	while (*start < end)
	{
		tab[i] = str[*start];
		i++;
		(*start)++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		j;
	int		i;
	int		k;

	i = 0;
	k = 0;
	tab = (char**)malloc(sizeof(char*) * (ft_space(str) + 2));
	while (str[i])
	{
		j = i;
		while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
			j++;
		if (j > i)
		{
			tab[k++] = word(str, &i, j);
		}
		else
		{
			i++;
		}
	}
	tab[k] = 0;
	return (tab);
}
