/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 14:45:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//exec_list

int	exec_new_node_alloc(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (FAILURE);
	tmp->args = NULL;
	tmp->rdir = NULL;
	tmp->next = NULL;
	tmp->fd[IN] = STDIN_FILENO;
	tmp->fd[OUT] = STDOUT_FILENO;
	tmp->pid = 0;
	addback_exec_node(*cmd, tmp);
	return (SUCCESS);
}

int	exec_list_create(t_cmd **cmd, t_token *expand_cmdline)
{
	t_token	*ptr;
	t_cmd	*head;
	int		ret;

	ptr = expand_cmdline;
	head = *cmd;
	while (ptr != NULL)
	{
		if (ptr->type == PIPE)
		{
			if (exec_new_node_alloc(cmd) == FAILURE)
				return (FAILURE);
			(*cmd) = (*cmd)->next;
		}
		else if (ptr->type == WORD)
			ret = append_arg_node(*cmd, ptr) == FAILURE;
		else
			ret = append_rdir_node(*cmd, ptr) == FAILURE;
		if (!(*cmd) || ret == FAILURE)
			return (FAILURE);
		ptr = ptr->next;
	}
	*cmd = head;
	return (SUCCESS);
}
