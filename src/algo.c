/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:29 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/20 04:24:41 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	insert(int index, int queue[], int *rear, int *queue_item_count)
{
	queue[++(*rear)] = index;
	(*queue_item_count)++;
}

static int	is_queue_empty(int queue_item_count)
{
	return (queue_item_count == 0);
}

static int	remove_data(int *queue_item_count, int queue[], int *front)
{
	(*queue_item_count)--;
	return (queue[(*front)++]);
}

static int	get_adj_unvisited_vertex(t_world *w, int vertex_index)
{
	int i;

	i = -1;
	while (++i < w->rooms[vertex_index].link_count)
		if (!w->rooms[w->rooms[vertex_index].links[i]].visited)
			return (w->rooms[vertex_index].links[i]);
	return (-1);
}

int			bfs_from(t_world *w, int start)
{
	t_data	d;
	int		queue[w->room_count];

	d.front = 0;
	d.rear = -1;
	d.queue_item_count = 0;
	d.unvisited_vertex = 0;
	w->rooms[start].visited = 1;
	w->rooms[start].distance = 0;
	insert(start, queue, &d.rear, &d.queue_item_count);
	while (!is_queue_empty(d.queue_item_count))
	{
		d.temp_vertex = remove_data(&d.queue_item_count, queue, &d.front);
		while ((d.unvisited_vertex =
			get_adj_unvisited_vertex(w, d.temp_vertex)) != -1)
		{
			d.distance = w->rooms[d.temp_vertex].distance;
			insert(d.unvisited_vertex, queue, &d.rear, &d.queue_item_count);
			w->rooms[d.unvisited_vertex].visited = 1;
			if (w->rooms[d.unvisited_vertex].type == END)
				return (d.distance + 1);
			w->rooms[d.unvisited_vertex].distance = d.distance + 1;
		}
	}
	return (-1);
}
