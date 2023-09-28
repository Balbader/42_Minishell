/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:40:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 12:29:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_data *in)
{
	in->cmd = NULL;
	
	if (exec_new_node_alloc(&in->cmd) == FAILURE)
		return ;
	if (exec_new_node_alloc(&in->cmd) == FAILURE)
		return ;
	if (exec_list_create(&in->cmd, in->cmd_line) == FAILURE)
		return ;
	launch_execution(in->cmd);
}
