/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:40:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/25 15:46:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec(t_data *in)
{
	in->cmd = NULL;
	
	if (exec_new_node_alloc(&in->cmd) == FAILURE)
		return (FAILURE);
	if (exec_list_create(&in->cmd, expand_cmdline) == FAILURE)
		return (FAILURE);
	execute(in->cmd);
}
