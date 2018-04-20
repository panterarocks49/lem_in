/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:09:12 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/20 02:01:45 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	parse_ants(t_world *world)
{
	char	*line;
	int		ant_count;

	if (!lemin_gnl(&line))
		error("No ants or bad ants.");
	ant_count = ft_atoi(line);
	if (!ft_strchr("0123456789", *line) || ant_count < 1)
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
	world->room_start = -1;
	world->room_end = -1;
}

static void	set_ants(t_world *world)
{
	int		i;

	i = -1;
	while (++i < world->ant_count)
		world->ants[i].room_index = world->room_start;
}

void		parse_input(t_world *world)
{
	set_world(world);
	parse_ants(world);
	parse_rooms(world);
	set_ants(world);
	ft_printf("\n");
}
