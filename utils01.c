/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:07:26 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/29 18:12:58 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;

	if (n == -2147483648)
		return (stdup("-2147483648"));
	if (n == 0)
		return (stdup("0"));
	i = ft_count(n);
	p = malloc(i + 1 * sizeof(char));
	if (!p)
		return (NULL);
	p[i--] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	while (n)
	{
		p[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (p);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		ret;

	s = ft_itoa(n);
	ret = ft_str_len(s);
	ft_putstr(s);
	free(s);
	return (ret);
}
