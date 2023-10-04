/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:40:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/29 12:16:21 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_token *in)
{
	t_cmd *cmd;

	if (exec_new_node_alloc(&cmd) == FAILURE)
		return ;
	if (exec_list_create(&cmd, in) == FAILURE)
		return ;
	ft_free_cmd(cmd);
	// ft_delete_all(&cmd_line);
	ft_del_env();
	rl_clear_history();
	// close(0);
	// return (SUCCESS);
	exit(120);

	launch_execution(cmd);
}
