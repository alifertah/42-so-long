/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:39:37 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/11 10:30:36 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up1(t_map *t, int i, int j)
{
	if (t->str[i - 1][j] == '0' || t->str[i - 1][j] == 'C')
	{
		t->str[i - 1][j] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		t->moves++;
		return (0);
	}
	if (t->str[i - 1][j] == '1')
		return (0);
	return (1);
}

void	ft_move_up(t_map *t)
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
				if (ft_move_up1(t, i, j) == 0)
					return ;
				if (t->str[i - 1][j] == 'E')
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

int	ft_move_left1(t_map *t, int i, int j)
{
	if (t->str[i][j - 1] == '0' || t->str[i][j - 1] == 'C')
	{
		t->str[i][j - 1] = 'P';
		t->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", t->moves);
		t->moves++;
		return (0);
	}
	if (t->str[i][j - 1] == '1')
		return (0);
	return (1);
}

int	ft_exit(void *ptr)
{
	(void) *ptr;
	exit(1);
}

void	ft_move_left(t_map *t)
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
				if (ft_move_left1(t, i, j) == 0)
					return ;
				if (t->str[i][j - 1] == 'E')
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
