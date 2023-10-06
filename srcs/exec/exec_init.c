/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/06 17:43:49 by ftuernal         ###   ########.fr       */
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

static void	exec_list_args_append(t_cmd **cmd, t_token *ptr)
{
	ptr->next = NULL;
	if (ptr->type == WORD)
		if ((*cmd)->args)
			goto_last_node((*cmd)->args)->next = ptr;
		else
			(*cmd)->args = ptr;
	else
		if ((*cmd)->rdir)
			goto_last_node((*cmd)->rdir)->next = ptr;
		else
			(*cmd)->rdir = ptr;
	return ;
}

int	exec_list_create(t_cmd **cmd, t_token *expand_cmdline)
{
	t_token	*ptr;
	t_cmd	*head;
	t_token *tmp;

	ptr = expand_cmdline;
	head = *cmd;
	while (ptr != NULL)
	{
		if (ptr->type == PIPE)
		{
			if (exec_new_node_alloc(&(*cmd)->next) == FAILURE)
				return (FAILURE);
			*cmd = (*cmd)->next;
			ptr = ptr->next;	
		}
		else
		{
			tmp = ptr;
			ptr = ptr->next;
			exec_list_args_append(cmd, tmp);
		}
	}
	*cmd = head;
print_cmd_nodes(*cmd);
printf("END OF TEST BEFORE EXEC\n\n\n\n\n");
	return (SUCCESS);
}
