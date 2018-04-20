/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:41:41 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/20 02:07:51 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	set_ants_unmoved(t_world *w)
{
	int i;

	i = -1;
	while (++i < w->ant_count)
		w->ants[i].moved = 0;
}

int		select_ant_placement(t_world *w, int place_from)
{
	int room;

	room = find_shortest_path_room(w, place_from);
	if (room >= w->room_count || room < 0)
		error("No way out.");
	return (room);
}

void	print_ants(t_world *w)
{
	int i;

	i = -1;
	ft_printf("Ant count: %d\n", w->ant_count);
	while (++i < w->ant_count)
	{
		ft_printf("ant:%d, room: %d\n", i, w->ants[i].room_index);
	}
}

int		find_ant(t_world *w, int room)
{
	int i;

	i = -1;
	while (++i < w->ant_count)
		if (w->ants[i].room_index == room && !w->ants[i].moved)
		{
			w->ants[i].room_index = room;
			w->ants[i].moved = 1;
			return (i);
		}
	return (-1);
}

void	place_ants(t_world *w)
{
	int i;
	int	ant;
	int moved;
	int room;

	moved = 1;
	print_world(w);
	print_ants(w);
	while (moved && !((moved = 0)))
	{
		set_ants_unmoved(w);
		i = -1;
		while (++i < w->room_count)
		{
			if (w->rooms[i].type != END && w->rooms[i].ants)
			{
				if ((room = select_ant_placement(w, i)) != -1 &&
					(w->rooms[room].ants == 0 || room == w->room_end))
				{
					if ((ant = find_ant(w, i) == -1))
						continue ;
					w->rooms[i].ants--;
					w->rooms[room].ants++;
					ft_printf("L%d-%s ", ant, w->rooms[room].name);
					i--;
					moved = 1;
				}
			}
		}
		if (moved)
			ft_printf("\n");
	}
}
