/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/21 17:05:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//exec_list
/*
	struct s_exec
	{
		t_node	*arg;
		t_node	*red;
		int		fd[2];
		int		pid;
		s_exec	*next;
	}
	les structures d'execution sont delimitees par les pipes.
	whenever you encounter a pipe you close the actual node and create a new
*/

/*
t_cmd	**exec_list_create(t_token *cmd_list)
{
	t_token	*ptr;
	t_cmd	*cmd;

	cmd = NULL;
	if (!cmd)
		return (NULL);
	ptr = cmd_list;
	while (ptr != NULL)
	{
		if (ptr->type == WORD)
		{
			cmd = add_cmd_wordnode(&cmd, *cmd_list);
			
	}
}
*/
