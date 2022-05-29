/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:39:55 by alfertah          #+#    #+#             */
/*   Updated: 2022/05/29 14:15:06 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_mmap
{
	int		c;
	int		e;
	int		p;
	int		fd;
	int		x;
	int		y;
	char	**str;
	char	*tab;
	int		i;
	int		j;
	int		len_str;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_put;
	void	*player;
	void	*collect;
	void	*walls;
	void	*enemy;
	void	*back;
	void	*exit;
	int		moves;
}	t_map;

char	*ft_line(char *str);
char	*ft_read(char *str, int fd);
int		ft_printf(const char *format, ...);
void	print(char c, va_list cp, int *s);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_unsigned_int(unsigned int n);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
int		check_len_first(char **str);
void	check_content(t_map *t);
int		check_len(char **str);
int		check_walls(char **str);
void	check_the_one(char **str);
int		ft_check_collect(t_map *t);
int		ft_move(int keycode, t_map *t);
int		ft_close(t_map *t);
void	ft_free(t_map *t);
int		ft_move(int keycode, t_map *t);
void	ft_move_down(t_map *t);
void	ft_move_up(t_map *t);
void	ft_move_left(t_map *t);
void	ft_move_right(t_map *t);
int		ft_move_down1(t_map *t, int i, int j);
int		ft_move_up1(t_map *t, int i, int j);
int		ft_move_left1(t_map *t, int i, int j);
int		ft_move_right1(t_map *t, int i, int j);
int		ft_exit(void *ptr);
void	ft_draw_map(t_map *t);
void	draw_map(t_map *t);
void	ft_free(t_map *t);
int		ft_move(int keycode, t_map *t);
void	ft_checkk(t_map *t);
int		ft_close_with_message(t_map *t);

#endif