/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 01:41:41 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 05:20:57 by nobrien          ###   ########.fr       */
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
		//ft_printf("%d\n", room);
		if (room >= w->room_count)
			return (-1);
		// ft_printf("%d\n", room);
		return (room);
	}
	return (-1);
}

int		find_ant(t_world *w, int room)
{
	int i;

	i = -1;
	while (++i < w->ant_count)
	{
		if (w->ants[i].room_index == room)
			return (i);
	}
	return (-1);
}

void    place_ants(t_world *w)
{
    int i;
    int	ant;
    int moved;
    int room;

    moved = 1;
    while (moved)
    {
        moved = 0;
        i = w->room_count;
        while (i >= 0)
        {
            if (w->rooms[i].type != END && w->rooms[i].ants)
            {
                if ((room = select_ant_placement(w, i)) != -1 && (w->rooms[room].ants == 0 || room == w->room_end))
                {
                	ant = find_ant(w, i);
                    w->rooms[i].ants--;
                    w->rooms[room].ants++;
                    w->ants[ant].room_index = room;
                    i++;
                    moved = 1;
					ft_printf("L%d-%s ", ant, w->rooms[room].name);
                }
            }
            i--;
        }
        if (moved)
       	 	ft_printf("\n");
    }
}
