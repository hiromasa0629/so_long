/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:23:31 by hyap              #+#    #+#             */
/*   Updated: 2022/07/08 12:30:03 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_BTN)
		exit_hook(game);
	game->keycode = keycode;
	mlx_loop_hook(game->mlx.mlx, re_render, game);
	return (0);
}
