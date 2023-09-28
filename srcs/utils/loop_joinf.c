/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_joinf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:04:24 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 16:38:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**loop_joinf(char **split_path, char *charset)
{
	t_list	*dump;
	char	**join_path;
	int		i;

	i = 0;
	join_path = ft_calloc(get_tab_len(split_path) + 1, sizeof(char *));
	dump = ft_calloc(1, sizeof(t_list));
	dump_add(split_path, dump);
	while (split_path[i] != 0)
	{
		join_path[i] = ft_strjoin(split_path[i], charset);
		dump_add(split_path[i], dump);
		i++;
	}
	join_path[i] = NULL;
	dump_add(split_path[i], dump);
	dump_del(dump);
	return (join_path);
}
