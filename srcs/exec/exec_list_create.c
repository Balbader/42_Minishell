/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:52:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/22 12:21:10 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//exec_list

int	exec_node_alloc(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = ft_calloc(1, sizeof(t_cmd));
	if (!tmp)
		return (FAILURE);
	tmp->arg = NULL;
	tmp->red = NULL;
	tmp->next = NULL;
	tmp->fd[IN] = STDIN_FILENO;
	tmp->fd[OUT] = STDOUT_FILENO;
	tmp->pid = 0;
	if (*cmd != 0)
// addback cmd_node
	else
		*cmd = tmp;
	return (SUCCESS);
}
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

int	exec_list_create(t_cmd **exec_cmdline, t_token *expand_cmdline)
{
	t_token	*head;

	head = expand_cmdline;
	while (expand_cmdline != 0)
	{
		if (expand_cmdline->type == WORD)
		{
			
		}
	}
	expand_cmdline = head;
	return (SUCCESS);
}

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
