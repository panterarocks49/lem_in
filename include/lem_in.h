/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:26:47 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/18 20:02:35 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdlib.h>
# include <libft.h>

# define STANDARD 0
# define START 1
# define END 2
// # define SNORLAX 3
// # define LAVA 4

typedef struct	s_room
{
	char	*name;
	int		ants;
	int		type;
	int		*links;
	int		link_count;
}				t_room;

typedef struct	s_ant
{
	int		room_index;
	int		*path;
}				t_ant;

typedef struct	s_world
{
	t_room	*rooms;
	int		room_start;
	int		room_end;
	int		room_count;
	t_ant	*ants;
	int		ant_count;
}				t_world;

void			parse_input(t_world *world);

int				find_room(t_world *world, char *name);
char			*parse_name(char *line);
void			parse_rooms(t_world *world);

void			parse_links(t_world *world, char *line);

void			*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int				lemin_gnl(char **line);

void			error(char *str);

#endif
