/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:42:11 by hyap              #+#    #+#             */
/*   Updated: 2022/07/08 14:16:22 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_complete(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (game->map.map[i])
	{
		str = game->map.map[i++];
		j = 0;
		while (str[j])
			if (str[j++] == 'C')
				return (0);
	}
	return (1);
}
