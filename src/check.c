/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 00:24:30 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/20 00:24:32 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	assert_start_end(t_world *w)
{
	if (w->room_start == -1 && w->room_end != -1)
		error("No room start.");
	else if (w->room_start == -1 && w->room_end == -1)
		error("No room start or end.");
	else if (w->room_start != -1 && w->room_end == -1)
		error("No room end.");
}

void		assert_rooms(t_world *w)
{
	assert_start_end(w);
}
