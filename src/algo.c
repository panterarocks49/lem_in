/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:29 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 04:41:58 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

// BFS (G, s)                   //Where G is the graph and s is the source node
//       let Q be queue.
//       Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

//       mark s as visited.
//       while ( Q is not empty)
//            //Removing that vertex from queue,whose neighbour will be visited now
//            v  =  Q.dequeue( )

//           //processing all the neighbours of v  
//           for all neighbours w of v in Graph G
//                if w is not visited 
//                         Q.enqueue( w )             //Stores w in Q to further visit its neighbour
//                         mark w as visited.

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
	int 	queue_item_count;
	int		queue[MAX];
	int		unvisited_vertex;
	int		front;
	int		temp_vertex;

	front = 0;
	rear = -1;
	queue_item_count = 0;
	unvisited_vertex = 0;
	w->rooms[start].visited = 1; //set first room as visited
	w->rooms[start].distance = 0; //set distance to first room to 0
	// ft_printf("%s, distance: %d\n", w->rooms[start].name, w->rooms[start].distance); //print the name of the first room
	insert(start, queue, &rear, &queue_item_count); //add the first room to the queue
	while (!is_queue_empty(queue_item_count)) //if there is nothing in queue, then there can be no adjacent rooms to search
	{
		temp_vertex = remove_data(&queue_item_count, queue, &front); //set the first item in the queue to the next one to search
		while ((unvisited_vertex = get_adj_unvisited_vertex(w, temp_vertex)) != -1) //if -1, temp vertex has no linked unvisited vertex
		{
			distance = w->rooms[temp_vertex].distance; //get distance of current vertex
			// ft_printf("%s, distance: %d\n", w->rooms[unvisited_vertex].name, distance + 1); //display that we're now going to visit this vertex (by adding to queue)
			insert(unvisited_vertex, queue, &rear, &queue_item_count); //add unvisited vertex to queue
			w->rooms[unvisited_vertex].visited = 1; //set it as visited, since added to queue
			if (w->rooms[unvisited_vertex].type == END)
				return (distance + 1);
			w->rooms[unvisited_vertex].distance = distance + 1; //set the next ones distance from base
		}
	}
	return (-1);
}

int		bfs(t_world *w)
{
	int		distance;
	int 	rear;
	int 	queue_item_count;
	int		queue[MAX];
	int		unvisited_vertex;
	int		front;
	int		temp_vertex;

	front = 0;
	rear = -1;
	queue_item_count = 0;
	unvisited_vertex = 0;
	w->rooms[w->room_start].visited = 1; //set first room as visited
	w->rooms[w->room_start].distance = 0; //set distance to first room to 0
	ft_printf("%s, distance: %d\n", w->rooms[w->room_start].name, w->rooms[w->room_start].distance); //print the name of the first room
	insert(w->room_start, queue, &rear, &queue_item_count); //add the first room to the queue
	while (!is_queue_empty(queue_item_count)) //if there is nothing in queue, then there can be no adjacent rooms to search
	{
		temp_vertex = remove_data(&queue_item_count, queue, &front); //set the first item in the queue to the next one to search
		while ((unvisited_vertex = get_adj_unvisited_vertex(w, temp_vertex)) != -1) //if -1, temp vertex has no linked unvisited vertex
		{
			distance = w->rooms[temp_vertex].distance; //get distance of current vertex
			ft_printf("%s, distance: %d\n", w->rooms[unvisited_vertex].name, distance + 1); //display that we're now going to visit this vertex (by adding to queue)
			insert(unvisited_vertex, queue, &rear, &queue_item_count); //add unvisited vertex to queue
			w->rooms[unvisited_vertex].visited = 1; //set it as visited, since added to queue
			w->rooms[unvisited_vertex].distance = distance + 1; //set the next ones distance from base
		}
	}
	return (0);
}















