/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:40:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 20:26:01 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_token *in)
{
	t_cmd	*cmd;

	print_all_words(in);
	if (exec_new_node_alloc(&cmd) == FAILURE)
		return ;
	if (exec_list_create(&cmd, in) == FAILURE)
		return ;
	launch_execution(cmd);
}
