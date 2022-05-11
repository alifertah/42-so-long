/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:39:46 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/11 10:29:57 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_right1(t_map *t, int i, int j)
{
	if (t->str[i][j + 1] == '0' || t->str[i][j + 1] == 'C')
	{
		t->str[i][j + 1] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		t->moves++;
		return (0);
	}
	if (t->str[i][j + 1] == '1')
		return (0);
	return (1);
}

void	ft_move_right(t_map *t)
{
	int	i;
	int	j;

	i = -1;
	while (t->str[++i])
	{
		j = 0;
		while (t->str[i][j])
		{
			if (t->str[i][j] == 'P')
			{
				if (ft_move_right1(t, i, j) == 0)
					return ;
				if (t->str[i][j + 1] == 'E')
				{
					if (ft_check_collect(t) == 0)
					{
						ft_printf("\033[0;33m=== YOU WON ===\n");
						exit(0);
					}
				}
			}
			j++;
		}
	}
}

int	ft_move_down1(t_map *t, int i, int j)
{
	if (t->str[i + 1][j] == '0' || t->str[i + 1][j] == 'C')
	{
		t->str[i + 1][j] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		t->moves++;
		return (0);
	}
	if (t->str[i + 1][j] == '1')
		return (0);
	return (1);
}

void	ft_move_down(t_map *t)
{
	int	i;
	int	j;

	i = -1;
	while (t->str[++i])
	{
		j = 0;
		while (t->str[i][j])
		{
			if (t->str[i][j] == 'P')
			{
				if (ft_move_down1(t, i, j) == 0)
					return ;
				if (t->str[i + 1][j] == 'E')
				{
					if (ft_check_collect(t) == 0)
					{
						ft_printf("\033[0;32m=== YOU WON ===\n");
						exit(0);
					}
				}
			}
			j++;
		}
	}
}

char	*ft_read(char *str, int fd)
{
	char	*buff;
	int		s1;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	s1 = 1;
	while (!ft_strchr(str, '\n') && s1 != 0)
	{
		s1 = read(fd, buff, BUFFER_SIZE);
		if (s1 == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[s1] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
