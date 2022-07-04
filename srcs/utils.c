/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:49:26 by hyap              #+#    #+#             */
/*   Updated: 2022/07/04 14:37:40 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
	write(fd, "\n", 1);
}

void	exit_error(char *s)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(s, 1);
	exit(1);
}

int	is_obstacles(char c)
{
	if (c == '1' || c == 'E')
		return (1);
	return (0);
}

int	exit_hook(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	exit(1);
}
