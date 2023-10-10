/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:25:16 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/10 13:25:18 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_run_builtins(char *path, t_cmd *cmd)
{
	int		exec;

	exec = false;
	if (ft_strcmp(path, "echo") == 0)
		exec = ft_exec_echo(cmd->args->next, cmd->fd[1]);
	else if (ft_strcmp(path, "cd") == 0)
		exec = ft_exec_cd(cmd->args->next, cmd->fd[0], cmd->fd[1]);
	else if (ft_strcmp(path, "pwd") == 0)
		exec = ft_exec_pwd(cmd->fd[1]);
	else if (ft_strcmp(path, "export") == 0)
		exec = ft_exec_export(cmd->args->next);
	else if (ft_strcmp(path, "unset") == 0)
		exec = ft_exec_unset(cmd->args->next);
	else if (ft_strcmp(path, "env") == 0)
		exec = ft_exec_env(cmd->fd[1]);
	else if (ft_strcmp(path, "exit") == 0)
		exec = ft_exec_exit(cmd->args->next, cmd);
	return (exec);
}
