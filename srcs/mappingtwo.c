/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappingtwo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:01:36 by hyap              #+#    #+#             */
/*   Updated: 2022/07/08 14:15:38 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_p(t_game *game, int i, int player_y)
{
	game->player.x = i;
	game->player.y = player_y;
	if (game->keycode == RIGHT_BTN)
		put_img(game, game->player_right);
	else if (game->keycode == LEFT_BTN)
		put_img(game, game->player_left);
	else if (game->keycode == UP_BTN)
		put_img(game, game->player_up);
	else if (game->keycode == DOWN_BTN || game->moved < 1)
		put_img(game, game->player_down);
}
