/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:27:30 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/19 00:27:32 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	parse_modifier(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (START);
	else if (!ft_strcmp(line, "##end"))
		return (END);
	return (STANDARD);
}

char		*parse_name(char *line)
{
	int		i;
	int		len;
	char	*name;

	len = 0;
	while (line[len] && line[len] != ' ' && line[len] != '-')
		len++;
	if (!(name = ft_strnew(len)))
		error("Malloc Failure ;(");
	i = -1;
	while (++i < len)
		name[i] = line[i];
	return (name);
}

int			find_room(t_world *world, char *name)
{
	int		i;

	i = -1;
	while (++i < world->room_count)
	{
		if (!ft_strcmp(world->rooms[i].name, name))
			return (i);
	}
	return (-1);
}

static void	add_room(t_world *world, char *name, int type)
{
	int	room_count;

	room_count = world->room_count;
	if (!(world->rooms = (t_room *)ft_realloc(world->rooms, sizeof(t_room) *
		room_count, sizeof(t_room) * (room_count + 1))))
		error("Malloc Failure ;(");
	world->rooms[room_count].name = name;
	world->rooms[room_count].visited = 0;
	world->rooms[room_count].ants = 0;
	world->rooms[room_count].type = type;
	world->rooms[room_count].links = NULL;
	world->rooms[room_count].link_count = 0;
	if (type == START)
	{
		world->rooms[room_count].ants = world->ant_count;
		world->room_start = room_count;
	}
	else if (type == END)
		world->room_end = room_count;
	world->room_count++;
}

void		parse_rooms(t_world *world)
{
	char	*line;
	char	*name;
	int		type;

	type = STANDARD;
	while (lemin_gnl(&line))
	{
		if (*line != '#')
		{
			name = parse_name(line);
			if (find_room(world, name) == -1)
				add_room(world, name, type);
			else
			{
				ft_strdel(&name);
				break ;
			}
		}
		type = parse_modifier(line);
		ft_strdel(&line);
	}
	parse_links(world, line);
}
