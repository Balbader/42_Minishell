/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:54:04 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/29 14:34:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	append_args_node(t_cmd **cmd, t_token *expand_cmdline)
{
	t_token	*last;

	if (!(*cmd)->args)
		(*cmd)->args = cmdline_new_node(expand_cmdline->word);
	else if (append_cmd_node((*cmd)->args, expand_cmdline->word) == FAILURE)
		return (FAILURE);
	last = goto_last_node((*cmd)->args);
	last->type = expand_cmdline->type;
	return (SUCCESS);
}

int	append_rdir_node(t_cmd **cmd, t_token *expand_cmdline)
{
	t_token	*last;

	if (!(*cmd)->rdir)
		(*cmd)->rdir = cmdline_new_node(expand_cmdline->word);
	else if (append_cmd_node((*cmd)->rdir, expand_cmdline->word) == FAILURE)
		return (FAILURE);
	last = goto_last_node((*cmd)->rdir);
	last->type = expand_cmdline->type;
	return (SUCCESS);
}

void	addback_exec_node(t_cmd *cmd, t_cmd *new)
{
	t_cmd	*last_ad;

	last_ad = goto_exec_last_node(cmd);
	if (cmd == NULL)
	{
		cmd = new;
		return ;
	}
	last_ad->next = new;
}

t_cmd	*goto_exec_last_node(t_cmd *head)
{
	t_cmd	*ptr;

	ptr = head;
	while (ptr != 0)
		ptr = ptr->next;
	return (ptr);
}

int	get_execargslen(t_token *args)
{
	int	i;
	t_token	*ptr;

	i = 0;
	ptr = args;
	while (ptr != 0)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
