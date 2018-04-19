/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:29 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 06:24:38 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	insert(int index, int queue[], int *rear, int *queue_item_count)
{
	queue[++(*rear)] = index;
	(*queue_item_count)++;
}

int		is_queue_empty(int queue_item_count)
{
	return (queue_item_count == 0);
}

int		remove_data(int *queue_item_count, int queue[], int *front)
{
	(*queue_item_count)--;
	return (queue[(*front)++]);
}

int		get_adj_unvisited_vertex(t_world *w, int vertex_index)
{
	int i;

	i = 0;
	while (i < w->rooms[vertex_index].link_count)
	{
		if (!w->rooms[w->rooms[vertex_index].links[i]].visited)
			return (w->rooms[vertex_index].links[i]);
		i++;
	}
	return (-1);
}

int		bfs_from(t_world *w, int start)
{
	int		distance;
	int 	rear;
	int		queue_item_count;
	int		queue[w->room_count];
	int		unvisited_vertex;
	int		front;
	int		temp_vertex;

	front = 0;
	rear = -1;
	queue_item_count = 0;
	unvisited_vertex = 0;
	w->rooms[start].visited = 1;
	w->rooms[start].distance = 0;
	insert(start, queue, &rear, &queue_item_count);
	while (!is_queue_empty(queue_item_count))
	{
		temp_vertex = remove_data(&queue_item_count, queue, &front);
		while ((unvisited_vertex = get_adj_unvisited_vertex(w, temp_vertex)) != -1)
		{
			distance = w->rooms[temp_vertex].distance;
			insert(unvisited_vertex, queue, &rear, &queue_item_count);
			w->rooms[unvisited_vertex].visited = 1;
			if (w->rooms[unvisited_vertex].type == END)
				return (distance + 1);
			w->rooms[unvisited_vertex].distance = distance + 1;
		}
	}
	return (-1);
}
