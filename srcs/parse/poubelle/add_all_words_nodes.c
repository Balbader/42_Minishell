/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_all_words_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:09:33 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/11 17:18:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*add_all_words_nodes( char **tab)
{
	t_token	*cmd_line;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			cmd_line = cmdline_new_node(tab[0]);
			if (!cmd_line)
				return (NULL);
		}
		else
			if (append_cmd_node(cmd_line, tab[i]) == FAILURE)
				return (NULL);
		if (!cmd_line)
			return (NULL);
		i++;
	}
	return (cmd_line);
}
