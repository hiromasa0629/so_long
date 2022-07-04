/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappingtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:01:36 by hyap              #+#    #+#             */
/*   Updated: 2022/07/01 13:09:06 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_p(t_game *game, int i, int player_y)
{
	game->player.x = i;
	game->player.y = player_y;
	if (game->keycode == RIGHT_BTN)
		put_img(game, PLAYER_RIGHT_PATH);
	else if (game->keycode == LEFT_BTN)
		put_img(game, PLAYER_LEFT_PATH);
	else if (game->keycode == UP_BTN)
		put_img(game, PLAYER_UP_PATH);
	else if (game->keycode == DOWN_BTN || game->moved < 1)
		put_img(game, PLAYER_DOWN_PATH);
}
