/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 05:31:06 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 16:47:18 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int             ft_whitespac(char c)
{
    if (c == ' ' || c == '\0' || c == '\n' || c == '\v' ||
            c == '\f' || c == '\r' || c == '\t')
        return (1);
    return (0);
}

int		ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	int			nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (ft_whitespac(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}
