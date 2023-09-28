/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:01:02 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 18:01:04 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*bis;

	while (cmd)
	{
		if (cmd->args)
			ft_delete_all(&cmd->args);
		if (cmd->rdir)
			ft_delete_all(&cmd->rdir);
		if (cmd->fd[0] != 0)
			close(cmd->fd[0]);
		if (cmd->fd[1] != 1)
			close(cmd->fd[1]);
		bis = cmd;
		cmd = bis->next;
		free(bis);
	}
}
