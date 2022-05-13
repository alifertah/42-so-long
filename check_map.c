/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:40:43 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/13 18:54:14 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_len(char **str)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str[i]);
	while (str[i] != NULL)
	{
		if (ft_strlen(str[i]) != len)
		{
			write(1, "len Error\n", 10);
			exit(1);
		}
		i++;
	}
	return (len);
}

int	check_len_first(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_content(t_map *t)
{
	t->c = 0;
	t->e = 0;
	t->p = 0;
	t->j = check_len_first(t->str) - 1;
	while (t->j > 0)
	{
		t->i = 0;
		while (t->str[t->j][t->i])
		{
			if (t->str[t->j][t->i] == 'C')
				t->c++;
			if (t->str[t->j][t->i] == 'P')
				t->p++;
			if (t->str[t->j][t->i] == 'E')
				t->e++;
		t->i++;
		}
	t->j--;
	}
	if (t->p != 1 || t->e < 1 || t->c < 1)
	{
		ft_printf("Error map!");
		ft_close(t);
	}
}

void	check_the_one(char **str)
{
	int	j;
	int	k;

	k = 0;
	j = ft_strlen(*str) - 1;
	while (k != check_len_first(str))
	{
		if (!(str[k][0] == '1' && str[k][j] == '1'))
		{
			ft_printf("Error walls!");
			exit(1);
		}
		k++;
	}
}

int	check_walls(char **str)
{
	int	i;
	int	j;

	j = check_len_first(str);
	i = 0;
	while (str[0][i] && str[j - 1][i])
	{
		if (str[0][i] == '1' && str[j - 1][i] == '1')
			i++;
		else
		{
			write(1, "ERROR walls\n", 15);
			exit(1);
		}	
	}
	return (0);
}
