/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 00:29:05 by jbrown            #+#    #+#             */
/*   Updated: 2018/04/19 23:50:07 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (old_size >= new_size || !(new = malloc(new_size)))
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	ft_memdel(&ptr);
	return (new);
}

int		find_room(t_world *world, char *name)
{
	int		i;

	i = -1;
	while (++i < world->room_count)
	{
		if (!ft_strcmp(world->rooms[i].name, name))
			return (i);
	}
	return (-1);
}

int		lemin_gnl(char **line)
{
	int	ret;

	while ((ret = get_next_line(0, line)) > 0)
	{
		ft_printf("%s\n", *line);
		if (**line != '#' || !ft_strcmp("##start", *line)
			|| !ft_strcmp("##end", *line))
			return (1);
		free(*line);
	}
	if (ret == -1)
		error("Read Error.");
	return (ret);
}
