/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback_cmdline_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:03:12 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/05 12:50:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	addback_cmdline_node(t_cmdlst **cmd_line, t_cmdlst *new)
{
	t_cmdlst	*last_ad;

	if (!(*cmd_line)->line)
	{
		*cmd_line = new;
		return ;
	}
	last_ad = goto_last_node(*cmd_line);
	last_ad->next = new;
}
