/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:39:10 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/10 13:39:14 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(char c, va_list cp, int *s)
{
	if (c == '%')
		*s += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		*s += ft_putnbr(va_arg(cp, int));
	else if (c == 'c')
		*s += ft_putchar(va_arg(cp, int));
	else if (c == 's')
		*s += ft_putstr(va_arg(cp, char *));
	else if (c == 'x')
		*s += ft_hexa(va_arg(cp, unsigned int), 1);
	else if (c == 'X')
		*s += ft_hexa(va_arg(cp, unsigned int), 0);
	else if (c == 'p')
	{
		ft_putstr("0x");
		*s += 2;
		*s += ft_hexa(va_arg(cp, unsigned long), 1);
	}
	else if (c == 'u')
		*s += ft_unsigned_int(va_arg(cp, unsigned int));
	else
		*s += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	cp;

	i = 0;
	va_start(cp, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (i);
			print(*format, cp, &i);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(cp);
	return (i);
}

char	*ft_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
