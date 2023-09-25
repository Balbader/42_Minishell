/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:31:28 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 15:31:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_run_builtins(char *path, t_cmd *cmd)
{
	int	exec;

	exec = false;
	if (ft_strcmp(path, "echo"))
		exec = ft_exec_echo(cmd->args->next, cmd->fd[OUT]);
	else if (ft_strcmp(path, "cd"))
		exec = ft_exec_cd(cmd->args->next, cmd->fd[IN], cmd->fd[OUT]);
	else if (ft_strcmp(path, "pwd"))
		exec = ft_exec_pwd(cmd->fd[OUT]);
}
