/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:43:17 by hyap              #+#    #+#             */
/*   Updated: 2022/07/08 14:12:24 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_wall_error(t_game *game)
{
	int		i;
	int		index;
	char	*line;

	index = 0;
	while (game->map.map[index])
	{
		i = 0;
		line = game->map.map[index];
		if (index == 0 || index == game->map.y - 1)
			while (line[i])
				if (line[i++] != '1')
					exit_error("Wall Error!");
		if (ft_strlen(line) != game->map.x)
			exit_error("Map Error!");
		if (index > 0)
			if (line[0] != '1' || line[game->map.x - 1] != '1')
				exit_error("Wall Error");
		index++;
	}
}

void	is_components(char c, t_components *comp)
{
	if (c == 'C')
		comp->has_c = 1;
	else if (c == 'E')
		comp->has_e = 1;
	else if (c == '1')
		comp->has_one = 1;
	else if (c == '0')
		comp->has_zero = 1;
	else if (c == 'P')
		comp->has_p++;
	else
		exit_error("Invalid component");
}

void	is_missing_components(t_components *comp)
{
	if (!comp->has_c)
		exit_error("Missing C");
	if (!comp->has_e)
		exit_error("Missing E");
	if (!comp->has_one)
		exit_error("Missing 1");
	if (comp->has_p > 1)
		exit_error("Only one P");
	if (!comp->has_p)
		exit_error("Missing P");
	if (!comp->has_zero)
		exit_error("Missing 0");
}

void	check_components(t_game *game, t_components *comp)
{
	int	index;
	int	i;

	index = 0;
	while (game->map.map[index] && index < game->map.y)
	{
		i = 0;
		while (game->map.map[index][i])
			is_components(game->map.map[index][i++], comp);
		index++;
	}
	is_missing_components(comp);
}

void	check_map(t_game *game)
{
	t_components	comp;

	comp.has_c = 0;
	comp.has_e = 0;
	comp.has_one = 0;
	comp.has_p = 0;
	comp.has_zero = 0;
	game->map.x = ft_strlen(game->map.map[0]);
	check_wall_error(game);
	check_components(game, &comp);
}
