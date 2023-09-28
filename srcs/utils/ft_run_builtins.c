/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:31:28 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/28 16:34:36 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_run_builtins(char *path, t_cmd *cmd)
{
	int	exec;

	exec = false;
	if (ft_strcmp(path, "echo"))
		exec = ft_exec_echo(cmd->args->next, cmd->fd[1]);
	else if (ft_strcmp(path, "cd"))
		exec = ft_exec_cd(cmd->args->next, cmd->fd[0], cmd->fd[1]);
	else if (ft_strcmp(path, "pwd"))
		exec = ft_exec_pwd(cmd->fd[1]);
	else if (ft_strcmp(path, "export"))
		exec = ft_exec_export(cmd->args->next);
	else if (ft_strcmp(path, "unset"))
		exec = ft_exec_unset(cmd->args->next);
	else if (ft_strcmp(path, "env"))
		exec = ft_exec_env(cmd->fd[1]);
	else if (ft_strcmp(path, "exit"))
		exec = ft_exec_exit(cmd->args->next, cmd);
	return (exec);
}
