/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:27:42 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/20 01:06:22 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_world	w;

	parse_input(&w);
	if (get_shortest_path_from(&w, w.room_start) == -1)
		error("No path.");
	place_ants(&w);
	return (0);
}
