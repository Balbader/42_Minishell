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
		if (cmd->arg)
			delall(&cmd->arg);
		if (cmd->red)
			delall(&cmd->red);
		if (cmd->fd[IN] != 0)
			close(cmd->fd[IN]);
		if (cmd->fd[OUT] != 1)
			close(cmd->fd[OUT]);
		bis = cmd;
		cmd = bis->next;
		free(bis);
	}
}
