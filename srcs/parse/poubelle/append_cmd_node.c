/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cmd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:48:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/11 16:03:17 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	append_cmd_node(t_token *cmd_line, char *line)
{
	t_token	*new_node;

	new_node = cmdline_new_node(line);
	if (!new_node)
		return (FAILURE);
	addback_cmdline_node(&cmd_line, new_node);
	return (SUCCESS);
}
