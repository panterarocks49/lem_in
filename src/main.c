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

static void	print_room(t_world *world, int i)
{
	t_room	*room;
	int		j;

	j = 0;
	room = world->rooms + i;
	if (i == world->room_start)
		ft_printf("\nSTART\n");
	else if (i == world->room_end)
		ft_printf("\nEND\n");
	else
		ft_printf("\nSTANARD\n");
	ft_printf("ID:    %d\n", i);
	ft_printf("NAME:  %s\n", room->name);
	ft_printf("ANTS:  %d\n", room->ants);
	ft_printf("TYPE:  %d\n", room->type);
	ft_printf("LINKS: ");
	while (j < room->link_count - 1)
		ft_printf("%d, ", room->links[j++]);
	ft_printf("%d\n", room->links[j]);
	ft_printf("COUNT: %d\n", room->link_count);
}

void		print_world(t_world *world)
{
	int		i;

	i = -1;
	ft_printf("ROOM COUNT: %d\n", world->room_count);
	while (++i < world->room_count)
		print_room(world, i);
}

int			main(void)
{
	t_world	w;

	parse_input(&w);
	if (get_shortest_path_from(&w, w.room_start) == -1)
		error("No path.");
	place_ants(&w);
	return (0);
}
