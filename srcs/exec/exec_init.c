/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/29 14:04:38 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_new_node_alloc(t_cmd **cmd)
{
	*cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (FAILURE);
	(*cmd)->args = NULL;
	(*cmd)->rdir = NULL;
	(*cmd)->next = NULL;
	(*cmd)->fd[IN] = STDIN_FILENO;
	(*cmd)->fd[OUT] = STDOUT_FILENO;
	(*cmd)->pid = 0;
	(*cmd)->next = NULL;
	return (SUCCESS);
}

static int	exec_list_args_append(t_cmd **cmd, t_token *ptr)
{
	int	ret;

	ret = SUCCESS;
	if (ptr->type == WORD)
		ret = append_args_node(cmd, ptr);
	else
		ret = append_rdir_node(cmd, ptr);
	return (ret);
}

int	exec_list_create(t_cmd **cmd, t_token *expand_cmdline)
{
	t_token	*ptr;
	t_cmd	*head;

	ptr = expand_cmdline;
	head = *cmd;
	while (ptr != NULL)
	{
		if (ptr->type == PIPE)
		{
			if (exec_new_node_alloc(&(*cmd)->next) == FAILURE)
				return (FAILURE);
			*cmd = (*cmd)->next;
		}
		else
			if (exec_list_args_append(cmd, ptr) == FAILURE)
				return (FAILURE);
		ptr = ptr->next;	
	}
	*cmd = head;
print_cmd_nodes(*cmd);
printf("END OF TEST BEFORE EXEC\n\n\n\n\n");
	return (SUCCESS);
}
