/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:40:35 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/13 18:49:33 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_drawmap(t_map *t)
{
	if (t->str[t->i][t->j] == '1')
	{
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->back, t->x, t->y);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->walls, t->x, t->y);
	}
	else if (t->str[t->i][t->j] == 'P')
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->player, t->x, t->y);
	else if (t->str[t->i][t->j] == 'E')
	{
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->back, t->x, t->y);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->exit, t->x, t->y);
	}
	else if (t->str[t->i][t->j] == 'C')
	{
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->back, t->x, t->y);
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->collect, t->x, t->y);
	}
	else if (t->str[t->i][t->j] == '0')
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->back, t->x, t->y);
}

void	draw_map(t_map *t)
{
	t->i = 0;
	t->j = 0;
	t->y = 0;
	mlx_clear_window(t->mlx_ptr, t->mlx_win);
	while (t->str[t->i])
	{
		t->x = 0;
		while (t->str[t->i][t->j])
		{
			ft_drawmap(t);
			t->j++;
			t->x += 64;
		}
		t->i++;
		t->j = 0;
		t->y += 64;
	}
}

void	draw2(t_map *t)
{
	t->mlx_win = mlx_new_window(t->mlx_ptr, check_len(t->str) * 64,
			check_len_first(t->str) * 64, "so_long -_-");
	t->player = mlx_xpm_file_to_image(t->mlx_ptr,
			"./xpmfile/player3.xpm", &(t->width), &(t->height));
	ft_checkk(t);
	t->walls = mlx_xpm_file_to_image(t->mlx_ptr,
			"./xpmfile/walls4.xpm", &(t->width), &(t->height));
	ft_checkk(t);
	t->collect = mlx_xpm_file_to_image(t->mlx_ptr,
			"./xpmfile/coin.xpm", &(t->width), &(t->height));
	ft_checkk(t);
	t->exit = mlx_xpm_file_to_image(t->mlx_ptr,
			"./xpmfile/exit_final.xpm", &(t->width), &(t->height));
	ft_checkk(t);
	t->back = mlx_xpm_file_to_image(t->mlx_ptr,
			"./xpmfile/background.xpm", &(t->width), &(t->height));
	ft_checkk(t);
}

void	ft_checkk(t_map *t)
{
	if (t->width == 0 || t->height == 0)
	{
		ft_printf("mlx error\n");
		exit(1);
	}
}

void	ft_draw_map(t_map *t)
{
	t->mlx_ptr = mlx_init();
	if (!t->mlx_ptr)
	{
		write(1, "Error --> mlx !!\n", 17);
		exit(1);
	}
	draw2(t);
	draw_map(t);
}
