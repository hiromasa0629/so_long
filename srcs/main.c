/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:44:21 by hyap              #+#    #+#             */
/*   Updated: 2022/07/04 14:57:41 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_game(t_game *game, char *map_path)
{
	game->map.x = 0;
	game->map.y = 0;
	game->moved = 0;
	game->mlx.mlx = mlx_init();
	mlx_xpm_file_to_image(game->mlx.mlx, "./img/tree.xpm",
		&game->sprite_x, &game->sprite_y);
	read_map(game, map_path);
	ft_printf("x: %d, y: %d\n", game->map.x * game->sprite_x,
		game->map.y * game->sprite_y);
	game->mlx.win = mlx_new_window(game->mlx.mlx, game->map.x * game->sprite_x,
			game->map.y * game->sprite_y, "So_Long");
	draw_map(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit_error("Map path!");
	init_game(&game, av[1]);
	mlx_key_hook(game.mlx.win, key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0L, exit_hook, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
