/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:41:41 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 02:56:56 by nobrien          ###   ########.fr       */
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
		// else
		// {
			room = find_shortest_path_room(w, place_from);
			ft_printf("Move ant from %s to %s\n", w->rooms[place_from].name, w->rooms[room].name);
			return (room);
		// }
	}
	return (-1);
}

void	place_ants(t_world *w)
{
	int i;
	int moved;
	int room;

	moved = 1;
	while (moved)
	{
		moved = 0;
		i = w->room_count - 1;
		while (i >= 0)
		{
			if (w->rooms[i].type != END && w->rooms[i].ants)
			{
				w->rooms[i].ants -= 1;
				room = select_ant_placement(w, i);
				if (room != -1)
				{
					w->rooms[room].ants += 1;
					moved = 1;
				}
			}
			i--;
		}
	}

}