/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatetwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:18:42 by hyap              #+#    #+#             */
/*   Updated: 2022/07/09 12:36:47 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_ber_ext(char *s)
{
	int		i;
	char	*ext;

	i = 0;
	ext = NULL;
	while (*s)
	{
		if (*s == '.')
			ext = s;
		s++;
	}
	if (ext == NULL || ft_strcmp(ext, ".ber") != 0)
		exit_error("Wrong extension");
}
