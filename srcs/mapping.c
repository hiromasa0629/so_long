/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:16:26 by hyap              #+#    #+#             */
/*   Updated: 2022/07/09 12:35:37 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_game *game, t_img img)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, img.img,
		game->draw_pos.x, game->draw_pos.y);
}

void	draw_line(t_game *game, char *line, int player_y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			put_img(game, game->wall);
		else if (line[i] == '0')
			put_img(game, game->ground);
		else if (line[i] == 'C')
			put_img(game, game->key);
		else if (line[i] == 'E')
			put_img(game, game->tent);
		else if (line[i] == 'P')
			handle_p(game, i, player_y);
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

void	save_map(t_game *game, char *map_path)
{
	int		index;
	int		fd;
	char	*line;

	index = 0;
	fd = open(map_path, O_RDONLY);
	while (index < game->map.y)
	{
		get_next_line(fd, &line);
		if (line[0] == '\0')
		{
			free(line);
			break ;
		}
		game->map.map[index++] = line;
	}
	close(fd);
}

void	read_map(t_game *game, char *map_path)
{
	int		fd;
	int		index;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_error("Wrong file");
	index = 1;
	while (index == 1)
	{
		index = get_next_line(fd, &line);
		if (line[0] != '\0')
			game->map.y++;
		free(line);
	}
	close(fd);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	game->map.map[game->map.y] = 0;
	save_map(game, map_path);
	check_map(game);
}
