/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:34:20 by hyap              #+#    #+#             */
/*   Updated: 2022/07/01 13:11:47 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_game *game)
{
	char	*s;

	s = game->map.map[game->player.y];
	if (!is_obstacles(game->map.map[game->player.y][game->player.x + 1]))
		game->player.x++;
	else
		return ;
	while (*s)
	{
		if (*s == 'P')
		{
			*s = '0';
			*++s = 'P';
			break ;
		}
		s++;
	}
}

void	move_left(t_game *game)
{
	char	*s;

	s = game->map.map[game->player.y];
	if (!is_obstacles(game->map.map[game->player.y][game->player.x - 1]))
		game->player.x--;
	else
		return ;
	while (*s)
	{
		if (*s == 'P')
		{
			*s = '0';
			*--s = 'P';
			break ;
		}
		s++;
	}
}

void	move_up(t_game *game)
{
	char	*s;
	char	*s2;

	s = game->map.map[game->player.y];
	if (!is_obstacles(game->map.map[game->player.y - 1][game->player.x]))
		game->player.y--;
	else
		return ;
	s2 = game->map.map[game->player.y];
	while (*s && *s2)
	{
		if (*s == 'P')
		{
			*s = '0';
			*s2 = 'P';
			break ;
		}
		s++;
		s2++;
	}
}

void	move_down(t_game *game)
{
	char	*s;
	char	*s2;

	s = game->map.map[game->player.y];
	if (!is_obstacles(game->map.map[game->player.y + 1][game->player.x]))
		game->player.y++;
	else
		return ;
	s2 = game->map.map[game->player.y];
	while (*s && *s2)
	{
		if (*s == 'P')
		{
			*s = '0';
			*s2 = 'P';
			break ;
		}
		s++;
		s2++;
	}
}

int	re_render(t_game *game)
{
	if (game->keycode == RIGHT_BTN)
		move_right(game);
	if (game->keycode == LEFT_BTN)
		move_left(game);
	if (game->keycode == UP_BTN)
		move_up(game);
	if (game->keycode == DOWN_BTN)
		move_down(game);
	draw_map(game);
	game->keycode = 0;
	return (0);
}
