/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:44:21 by hyap              #+#    #+#             */
/*   Updated: 2022/07/09 12:28:17 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	save_img(t_game *game, char *path)
{
	t_img	img;
	int		x;
	int		y;

	img.img = mlx_xpm_file_to_image(game->mlx.mlx, path, &x, &y);
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.size, &img.endian);
	return (img);
}

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
	game->wall = save_img(game, TREE_PATH);
	game->ground = save_img(game, GROUND_PATH);
	game->player_up = save_img(game, PLAYER_UP_PATH);
	game->player_down = save_img(game, PLAYER_DOWN_PATH);
	game->player_right = save_img(game, PLAYER_RIGHT_PATH);
	game->player_left = save_img(game, PLAYER_LEFT_PATH);
	game->tent = save_img(game, TENT_PATH);
	game->key = save_img(game, KEY_PATH);
	draw_map(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		exit_error("Map path!");
	check_ber_ext(av[1]);
	init_game(&game, av[1]);
	mlx_key_hook(game.mlx.win, key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0L, exit_hook, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
