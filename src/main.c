/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:27:42 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/19 03:07:45 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_world w;

	w.room_count = 4;
	set_unvisited(&w);
	init_ants(&w);
	w.room_start = 0;
	w.rooms[0].name = "room 0";
	w.rooms[0].links[0] = 1;
	w.rooms[0].links[1] = 2;
	w.rooms[0].link_count = 2;
	w.rooms[0].type = START;
	w.rooms[0].ants = 5;

	w.rooms[1].name = "room 1";
	w.rooms[1].links[0] = 4;//commenting this out increases the length to room 4, has to take different path
	w.rooms[1].link_count = 1;//need to adjust to 0 if adjusting lenght ^^
	w.rooms[1].type = STANDARD;

	// w.rooms[1].name = "room 1 across";
	// w.rooms[1].links[0] = 2;
	// w.rooms[1].link_count = 1;
	// w.rooms[1].type = STANDARD;

	// w.rooms[1].name = "room 1 looper";
	// w.rooms[1].links[0] = 0;
	// w.rooms[1].link_count = 1;
	// w.rooms[2].type = STANDARD;

	w.rooms[2].name = "room 2";
	w.rooms[2].links[0] = 3;
	w.rooms[2].link_count = 1;
	w.rooms[2].type = STANDARD;

	w.rooms[3].name = "room 3";
	w.rooms[3].links[0] = 4;
	w.rooms[3].link_count = 1;
	w.rooms[3].type = STANDARD;

	w.rooms[4].name = "room 4";
	w.rooms[4].link_count = 0;
	w.rooms[4].type = END;

	place_ants(&w);

	// 0->1 0->2
	// 1->4 2->3
	// 3->4
	return (0);
}
