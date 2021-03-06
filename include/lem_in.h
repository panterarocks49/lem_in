/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:21:35 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/20 05:19:17 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <libft.h>

# define STANDARD 0
# define START 1
# define END 2

typedef struct	s_room
{
	char		*name;
	int			ants;
	int			type;
	int			*links;
	int			link_count;
	int			visited;
	int			distance;
}				t_room;

typedef struct	s_ant
{
	int			room_index;
	int			moved;
	int			last_spot;
}				t_ant;

typedef struct	s_world
{
	t_room		*rooms;
	int			room_start;
	int			room_end;
	int			room_count;
	t_ant		*ants;
	int			ant_count;
}				t_world;

typedef struct	s_data
{
	int			distance;
	int			rear;
	int			queue_item_count;
	int			unvisited_vertex;
	int			front;
	int			temp_vertex;
}				t_data;

void			assert_rooms(t_world *w);

void			parse_input(t_world *world);

void			parse_rooms(t_world *world);

void			print_world(t_world *world);

void			parse_links(t_world *world, char *line);

void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int				find_room(t_world *world, char *name);
int				lemin_gnl(char **line);

void			error(char *str);

int				bfs_from(t_world *w, int start);

int				get_shortest_path_from(t_world *w, int path_from);
int				find_shortest_path_room(t_world *w, int path_from, int ant);

void			place_ants(t_world *w);

#endif
