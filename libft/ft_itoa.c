/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:01:03 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/04 14:46:39 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlennbr(int n)
{
	int				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	long			tmp;
	char			*str;
	unsigned int	len;

	tmp = (long)n;
	str = NULL;
	len = ft_strlennbr(tmp) + (n < 0);
	if (n < 0)
		tmp = (tmp * -1);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[len - 1] = (tmp % 10) + '0';
		len--;
		tmp = tmp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
