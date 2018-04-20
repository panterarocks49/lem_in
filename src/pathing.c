/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:49:04 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/20 02:55:28 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	set_unvisited(t_world *w)
{
	int i;

	i = -1;
	while (++i < w->room_count)
		w->rooms[i].visited = 0;
}

int		get_shortest_path_from(t_world *w, int path_from)
{
	set_unvisited(w);
	return (bfs_from(w, path_from));
}

int		find_shortest_path_room(t_world *w, int path_from)
{
	int i;
	int min;
	int best_room;
	int distance;

	i = -1;
	min = 2147483647;
	best_room = -1;
	while (++i < w->rooms[path_from].link_count)
	{
		if (w->rooms[w->rooms[path_from].links[i]].type != END
			&& w->rooms[w->rooms[path_from].links[i]].ants)
			continue ;
		if ((distance = (get_shortest_path_from(w,
			w->rooms[path_from].links[i]))) < min)
		{
			min = distance;
			best_room = w->rooms[path_from].links[i];
		}
	}
	return (best_room);
}
