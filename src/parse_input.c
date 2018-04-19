/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:09:12 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/19 06:25:41 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	parse_ants(t_world *world)
{
	char	*line;
	int		ant_count;

	if (!lemin_gnl(&line))
		error("No ants or bad ants.");
	if (!(ant_count = ft_atoi(line)))
		error("No ants or bad ants.");
	free(line);
	if (!(world->ants = (t_ant *)malloc(sizeof(t_ant) * ant_count)))
		error("Malloc Failure ;(");
	world->ant_count = ant_count;
}

static void	set_world(t_world *world)
{
	world->room_count = 0;
	world->rooms = NULL;
	world->ant_count = 0;
	world->ants = NULL;
}

static void	set_ants(t_world *world)
{
	int		i;

	i = -1;
	while (++i < world->ant_count)
		world->ants[i].room_index = world->room_start;
}

void		print_room(t_world *world, int i)
{
	t_room	*room;
	int		j;

	j = 0;
	room = world->rooms + i;
	if (i == world->room_start)
		ft_printf("\nSTART\n");
	else if (i == world->room_end)
		ft_printf("\nEND\n");
	else
		ft_printf("\nSTANARD\n");
	ft_printf("ID:    %d\n", i);
	ft_printf("NAME:  %s\n", room->name);
	ft_printf("ANTS:  %d\n", room->ants);
	ft_printf("TYPE:  %d\n", room->type);
	ft_printf("LINKS: ");
	while (j < room->link_count - 1)
		ft_printf("%d, ", room->links[j++]);
	ft_printf("%d\n", room->links[j]);
	ft_printf("COUNT: %d\n", room->link_count);
}

void		print_world(t_world *world)
{
	int		i;

	i = -1;
	ft_printf("ROOM COUNT: %d\n", world->room_count);
	while (++i < world->room_count)
		print_room(world, i);
}

void		parse_input(t_world *world)
{
	set_world(world);
	parse_ants(world);
	parse_rooms(world);
	set_ants(world);
	ft_printf("\n");
}
