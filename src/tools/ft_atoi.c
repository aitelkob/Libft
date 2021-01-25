/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:08:20 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:08:21 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	reste;
	int	i;

	i = 0;
	reste = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		str++;
	if (*str == '-' || *str == '+')
		i = 1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		reste = (reste * 10) + (str[i] - '0');
		i++;
	}
	if (*str == '-')
		return (-reste);
	return (reste);
}
