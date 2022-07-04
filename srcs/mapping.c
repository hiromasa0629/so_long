/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:16:26 by hyap              #+#    #+#             */
/*   Updated: 2022/07/04 14:35:39 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_game *game, char *path)
{
	int	x;
	int	y;

	game->img.img = mlx_xpm_file_to_image(game->mlx.mlx, path, &x, &y);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.size, &game->img.endian);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img,
		game->draw_pos.x, game->draw_pos.y);
}

void	put_player(t_game *game, char *path)
{
	int	x;
	int	y;

	game->img.img = mlx_xpm_file_to_image(game->mlx.mlx, path, &x, &y);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.size, &game->img.endian);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img,
		game->player.x * game->sprite_x, game->player.y * game->sprite_x);
}

void	draw_line(t_game *game, char *line, int player_y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			put_img(game, TREE_PATH);
		else if (line[i] == '0')
			put_img(game, GROUND_PATH);
		else if (line[i] == 'C')
			put_img(game, KEY_PATH);
		else if (line[i] == 'E')
			put_img(game, TENT_PATH);
		else if (line[i] == 'P')
		{
			handle_p(game, i, player_y);
		}
		game->draw_pos.x += game->sprite_x;
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;

	i = 0;
	game->draw_pos.x = 0;
	game->draw_pos.y = 0;
	while (game->map.map[i])
	{
		game->draw_pos.x = 0;
		draw_line(game, game->map.map[i], i);
		i++;
		game->draw_pos.y += game->sprite_y;
	}
}

void	read_map(t_game *game, char *map_path)
{
	int		fd;
	int		index;
	char	*line;

	fd = open(map_path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		game->map.y++;
		free(line);
	}
	free(line);
	fd = open(map_path, O_RDONLY);
	index = 0;
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	game->map.map[game->map.y] = 0;
	while (get_next_line(fd, &line) && index < game->map.y)
		game->map.map[index++] = line;
	free(line);
	check_map(game);
}
