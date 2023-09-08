/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cmd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:48:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/06 13:00:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	append_cmd_node(t_data *in, int start, int len)
{
	t_cmdlst	*new_node;

	new_node = cmdline_new_node(in->input, start, len);
	if (!new_node)
		return (FAILURE);
	addback_cmdline_node(&in->cmd_line, new_node);
	return (SUCCESS);
}
