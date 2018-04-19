/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:21:35 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 02:51:08 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>
# define STANDARD 0
# define START 1
# define END 2
// # define SNORLAX 3
// # define LAVA 4
# define MAX 1000//temp num, rooms count?

typedef struct	s_room
{
	char	*name;
	int		ants;
	int		type;
	int		links[2];
	// int		*links;
	int		link_count;
	int		visited;
	int		distance;
}				t_room;

typedef struct	s_ant
{
	int		room_index;
	int		*path;
}				t_ant;

typedef struct	s_world
{
	// t_room	*rooms;
	t_room	rooms[5];
	int		room_start; //index of rooms
	int		room_count;
	t_ant	*ants;
}				t_world;

int		bfs(t_world *w);
int		bfs_from(t_world *w, int start);
void	set_unvisited(t_world *w);
void	init_ants(t_world *w);
int		get_shortest_path_from(t_world *w, int path_from);
int		find_shortest_path_room(t_world *w, int path_from);
int		select_ant_placement(t_world *w, int place_from);
void	place_ants(t_world *w);

#endif
