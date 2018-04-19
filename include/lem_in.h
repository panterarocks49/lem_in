/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:26:47 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/18 20:02:35 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>
# define STANDARD 0
# define START 1
# define END 2
// # define SNORLAX 3
// # define LAVA 4

typedef struct	s_room
{
	char	*name;
	int		number;
	int		ants;
	int		type;
	int		*links;
}				t_room;

typedef struct	s_world
{
	t_room	*rooms;
	int		start_idx;
}				t_world;

typedef struct	s_ant
{
	char	*location;
	int		number;
	int		*path
}				t_ant;

#endif
