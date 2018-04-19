/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:41:41 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 04:41:18 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		select_ant_placement(t_world *w, int place_from)
{
	int i;
	int room;

	i = -1;
	while (++i < w->rooms[place_from].link_count)
	{
		// if (w->rooms[place_from].type == START)
		// {
		// 	if (get_shortest_path_from(w, place_from) < w->rooms[place_from].ants)
		// 		ft_printf("Move ant from %s to %s\n", w->rooms[place_from].name, w->rooms[find_shortest_path_room(w, place_from)].name);
		// 	return ;
		// 	//need to add an else that checks if all paths are longer than the ant count then use the shortest, maybe in the moving loop though
		// }
		room = find_shortest_path_room(w, place_from);
		ft_printf("%d\n", room);
		if (room >= w->room_count)
			return (room);
		ft_printf("Move ant from %s to %s\n", w->rooms[place_from].name, w->rooms[room].name);
		return (room);
	}
	return (-1);
}

void	reset_ants(t_world *w)
{
	int	i;

	i = -1;
	while (++i < w->ant_count)
		w->ants[i++].moved = 0;
}

void	place_ants(t_world *w)
{
	int i;
	int j;
	int room;

	j = 0;
	while (j++ < 10)//w->rooms[w->room_end].ants != w->ant_count)
	{
		i = -1;
		while (++i < w->ant_count)
		{
			if (!w->ants[i].moved && w->ants[i].room_index != w->room_end && w->rooms[w->ants[i].room_index].ants)
			{
				room = select_ant_placement(w, w->ants[i].room_index);
				if (room > -1 && room < w->room_count)
				{
					w->rooms[w->ants[i].room_index].ants--;
					w->rooms[room].ants++;
					w->ants[i].room_index = room;
					w->ants[i].moved = 1;
					i = -1;
				}
			}
		}
		reset_ants(w);
		// i = w->room_count - 1;
		// while (i >= 0)
		// {
		// 	if (w->rooms[i].type != END && w->rooms[i].ants)
		// 	{
		// 		room = select_ant_placement(w, i);
		// 		if (room != -1)
		// 		{
		// 			w->rooms[i].ants--;
		// 			w->rooms[room].ants++;
		// 			i++;
		// 		}
		// 	}
		// 	i--;
		// }
		ft_printf("\n");
	}
}