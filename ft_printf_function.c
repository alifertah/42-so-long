/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:39:03 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/10 13:39:06 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_unsigned_int(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += (ft_unsigned_int(n / 10));
		len += (ft_unsigned_int(n % 10));
	}
	else
		len += (ft_putchar(n + 48));
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		write (1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += (ft_putstr("-214748364"));
		n = 8;
	}
	if (n < 0)
	{
		len += (ft_putchar('-'));
		n = -n;
	}
	if (n > 9)
	{
		len += (ft_putnbr(n / 10));
		len += (ft_putnbr(n % 10));
	}
	else
		len += (ft_putchar(n + 48));
	return (len);
}

int	ft_hexa(unsigned long n, int s)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_hexa(n / 16, s);
	if (n % 16 < 10)
		len += ft_putchar((n % 16) + 48);
	else
	{
		if (s == 1)
			len += ft_putchar((n % 16) + 87);
		else
			len += ft_putchar((n % 16) + 55);
	}
	return (len);
}
