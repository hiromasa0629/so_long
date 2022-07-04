/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:47:42 by hyap              #+#    #+#             */
/*   Updated: 2022/07/01 13:12:27 by hyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TREE_PATH "./img/tree.xpm"
# define GROUND_PATH "./img/ground.xpm"
# define KEY_PATH "./img/key.xpm"
# define TENT_PATH "./img/tent.xpm"
# define PLAYER_DOWN_PATH "./img/link_down.xpm"
# define PLAYER_UP_PATH "./img/link_up.xpm"
# define PLAYER_LEFT_PATH "./img/link_left.xpm"
# define PLAYER_RIGHT_PATH "./img/link_right.xpm"
# define RIGHT_BTN 124
# define LEFT_BTN 123
# define UP_BTN 126
# define DOWN_BTN 125
# define ESC_BTN 53
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./mlx.h"
# include "./ft_printf.h"
# include "../gnl/get_next_line_bonus.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		size;
	int		x;
	int		y;
	int		endian;
}				t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_map {
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_player {
	int	x;
	int	y;
}				t_player;

typedef struct s_game {
	t_mlx		mlx;
	t_img		img;
	t_map		map;
	t_pos		draw_pos;
	t_player	player;
	int			sprite_x;
	int			sprite_y;
	int			keycode;
	int			moved;
}				t_game;

typedef struct s_components {
	int	has_zero;
	int	has_one;
	int	has_c;
	int	has_e;
	int	has_p;
}				t_components;

void			put_img(t_game *game, char *path);
void			ft_putendl_fd(char *s, int fd);
void			exit_error(char *s);
void			draw_map(t_game *game);
void			check_map(t_game *game);
void			read_map(t_game *game, char *map_path);
void			handle_p(t_game *game, int i, int player_y);
int				key_hook(int keycode, t_game *game);
int				re_render(t_game *game);
int				is_obstacles(char c);
int				exit_hook(t_game *game);

#endif