/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:51:31 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/05 08:05:01 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exeedsnbr(int negative, int breaknbr)
{
	if (negative <= -1 && breaknbr >= 19)
		return (0);
	else if (negative >= 1 && breaknbr >= 19)
		return (-1);
	else
		return (1);
}

static int	nextcharlegal(const char *str, int breaknbr)
{
	if (!(*str >= '0' && *str <= '9'))
	{
		if (*str == '\e')
			return (0);
		if ((*str >= 0 && *str <= 32) && breaknbr == 0)
			return (1);
		else if ((*str == '+' || *str == '-') && breaknbr == 0)
		{
			str++;
			if ((*str >= '0' && *str <= '9'))
			{
				if (*str-- == '+')
					return (1);
				else if (*str-- == '-')
					return (-1);
			}
			else
				return (0);
		}
		else if (breaknbr == 0)
			return (0);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int	nbr;
	int	negative;
	int	breaknbr;

	breaknbr = 0;
	negative = 1;
	nbr = 0;
	while (*str)
	{
		if (nextcharlegal(str, breaknbr) == -1 && negative == 1)
			negative = -1;
		else if (nextcharlegal(str, breaknbr) == 0)
			return (nextcharlegal(str, breaknbr));
		if (*str >= '0' && *str <= '9' && breaknbr++ >= 0)
		{
			nbr = nbr * 10 + (*str - '0');
			if (exeedsnbr(negative, breaknbr) != 1)
				return (exeedsnbr(negative, breaknbr));
		}
		else if (!(*str >= '0' && *str <= '9') && breaknbr > 0)
			break ;
		str++;
	}
	nbr *= negative;
	return (nbr);
}
