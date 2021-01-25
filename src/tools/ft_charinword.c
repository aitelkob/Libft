/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charinword.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:07:45 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 10:07:46 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charinword(char *str, size_t i, char stop)
{
	size_t	begin;

	begin = i;
	while (str[i] != stop && str[i])
		i++;
	return (i - begin);
}
