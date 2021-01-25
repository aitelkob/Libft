/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:08:08 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:08:10 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_len(char *base)
{
	int	len_base;
	int	j;

	len_base = 0;
	while (base[len_base])
	{
		if (base[len_base] == '-' || base[len_base] == '+')
			return (0);
		j = len_base + 1;
		while (base[j])
		{
			if (base[len_base] == base[j])
				return (0);
			++j;
		}
		++len_base;
	}
	if (len_base < 2)
		return (0);
	return (len_base);
}

static int	check_base_str(char *str, char *base)
{
	int	i;
	int	j;
	int	start;

	start = 0;
	while (str[start] != '\0' && (str[start] == ' '
				|| str[start] == '\t' || str[start] == '\n'))
		start++;
	i = start;
	while (str[i])
	{
		j = 0;
		while (base[j] && (str[i] != base[j] ||
					(str[i] == '-' || str[i] == '+')))
			++j;
		if (str[i] != base[j] && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static int	get_from_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int	s;
	int	i;
	int	res;
	int	signe;
	int	len_base;

	if (!(len_base = base_len(base)) || !check_base_str(str, base))
		return (0);
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' ||
				str[s] == '\t' || str[s] == '\n'))
		s++;
	i = s - 1;
	res = 0;
	signe = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
				(str[i] != '-' && str[i] != '+')))
	{
		if (str[i] == '-')
			signe = -1;
		else if (str[i] != '+')
			res = (res * len_base) + (get_from_base(str[i], base));
	}
	return (res * signe);
}
