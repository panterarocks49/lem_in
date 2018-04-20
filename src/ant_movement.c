/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:41:41 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/20 03:04:22 by nobrien          ###   ########.fr       */
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
	return (room);
}

void	print_ants(t_world *w)
{
	int i;

	i = -1;
	ft_printf("Ant count: %d\n", w->ant_count);
	while (++i < w->ant_count)
	{
		ft_printf("ant:%d, room: %d, moved?: %d\n", i, w->ants[i].room_index, w->ants[i].moved);
	}
}

int		find_ant(t_world *w, int room)
{
	int i;

	i = -1;
	while (++i < w->ant_count)
		if (w->ants[i].room_index == room && !w->ants[i].moved)
		{
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
	while (moved && !((moved = 0)))
	{
		set_ants_unmoved(w);
		i = -1;
		while (++i < w->room_count)
		{
			if (w->rooms[i].type != END && w->rooms[i].ants && (ant = find_ant(w, i)) != -1)
			{
				if ((room = select_ant_placement(w, i)) != -1 &&
					(w->rooms[room].ants == 0 || room == w->room_end))
				{
					if (get_shortest_path_from(w, i) < get_shortest_path_from(w, room) || get_shortest_path_from(w, room) < w->rooms[w->room_start].ants)
						continue ;
					w->ants[ant].room_index = room;
					w->rooms[i].ants--;
					w->rooms[room].ants++;
					w->ants[ant].moved = 1;
					ft_printf("L%d-%s ", ant + 1, w->rooms[room].name);
					i = -1;
					moved = 1;
				}
			}
		}
		if (moved)
			ft_printf("\n");
	}
}
