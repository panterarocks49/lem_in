/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:27:33 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/19 01:27:34 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	link_rooms(t_world *world, int a, int b)
{
	int	*links;
	int	link_count;

	links = world->rooms[a].links;
	link_count = world->rooms[a].link_count;
	if (!(links = (int *)ft_realloc(links, sizeof(int) * link_count,
			sizeof(int) * (link_count + 1))))
		error("Malloc Failure ;(");
	links[link_count] = b;
	world->rooms[a].link_count++;
	world->rooms[a].links = links;
}

static void	add_link(t_world *world, char *line)
{
	char	*name;
	int		a;
	int		b;

	name = parse_name(line);
	a = find_room(world, name);
	ft_strdel(&name);
	while (*line && *line != ' ' && *line != '-')
		line++;
	line++;
	name = parse_name(line);
	b = find_room(world, name);
	ft_strdel(&name);
	if (a < 0 || b < 0)
		error("Bad links.");
	link_rooms(world, a, b);
	link_rooms(world, b, a);
}

void		parse_links(t_world *world, char *line)
{
	while (1)
	{
		if (*line != '#')
			add_link(world, line);
		ft_strdel(&line);
		if (!lemin_gnl(&line))
			break ;
	}
	ft_strdel(&line);
}
