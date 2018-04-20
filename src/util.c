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

int		lemin_gnl(char **line)
{
	int	ret;

	while ((ret = get_next_line(0, line)) > 0)
	{
		ft_printf("%s\n", *line);
		if ((**line == '#' && *(*line + 1) == '#') || **line != '#')
			return (1);
		free(*line);
	}
	if (ret == -1)
		error("Read Error.");
	return (ret);
}
