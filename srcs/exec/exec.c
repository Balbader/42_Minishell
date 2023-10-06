/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:40:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/06 17:43:40 by ftuernal         ###   ########.fr       */
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
 //ft_delete_all(&in);
//	ft_free_cmd(cmd);
//	ft_del_env();
//exit(126);
//	rl_clear_history();
	// close(0);
	// return (SUCCESS);
	launch_execution(cmd);
}
