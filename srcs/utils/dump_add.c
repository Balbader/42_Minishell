/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:15:12 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 14:39:18 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

void	dump_add(void *content, t_list *garbage)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_back(&garbage, new);
}

void	add_str_to_dump(char **paths, t_list *dump)
{
	int		i;

	i = 0;
	dump_add(paths, dump);
	while (paths[i] != 0)
	{
		dump_add(paths[i], dump);
		i++;
	}
	dump_add(paths[i], dump);
}

