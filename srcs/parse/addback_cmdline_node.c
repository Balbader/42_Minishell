/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback_cmdline_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:03:12 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/08 06:54:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	addback_cmdline_node(t_token **cmd_line, t_token *new)
{
	t_token	*last_ad;

	if (!*cmd_line)
	{
		*cmd_line = new;
		return ;
	}
	last_ad = goto_last_node(*cmd_line);
	last_ad->next = new;
}
