/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:25:09 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/19 19:10:42 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_contword(char const *str, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ((i == 0 && str[i] != c) || (str[i] != c && str[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}
