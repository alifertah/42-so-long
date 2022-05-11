/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:39:18 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/10 13:39:20 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	len = -1;
	while (s1[++len])
		str[len] = s1[len];
	j = 0;
	while (s2[j])
	{
		str[len++] = s2[j++];
	}
	str[len] = '\0';
	free(s1);
	return (str);
}

char	*ft_rest(char *st)
{
	size_t	i;
	size_t	k;
	char	*rest;

	i = 0;
	while (st[i] != '\n' && st[i])
		i++;
	if (ft_strlen(st) == i)
	{
		free(st);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(st) - i + 1));
	if (!rest)
		return (NULL);
	k = 0;
	while (st[i++])
	{
		rest[k] = st[i];
		k++;
	}
	rest[k] = '\0';
	free(st);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (str == NULL )
		return (NULL);
	line = ft_line(str);
	str = ft_rest(str);
	return (line);
}
