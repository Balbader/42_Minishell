/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:43:18 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/29 16:35:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_child(t_cmd *cmd, t_cmd *start)
{
	char	**env_tab;
	char	**cmd_tab;
	char	*path;

	cmd_tab = convert_arg_to_tab(cmd->args);
	env_tab = ft_convert_env_to_tab(*ft_get_env(0, 0, 0)); 
	path = init_path(cmd_tab[0], env_tab);
//debug
printf("------ARGS SENT TO EXECVE-----\n");
printf("PATH == %s\n", path);
printf("PATH == %p\n", cmd_tab);
printf("PATH == %p\n", env_tab);
printf("------------------------------------\n");
//end of debug
	if (cmd->fd[IN] != STDIN_FILENO)
	{
		dup2(cmd->fd[IN], STDIN_FILENO);
		close(cmd->fd[IN]);
	}
	if (cmd->fd[OUT] != STDOUT_FILENO)
	{
		dup2(cmd->fd[OUT], STDOUT_FILENO);
		close(cmd->fd[OUT]);
	}
	rm_command_node(&start, cmd);
	if (path)
	{
		ft_init_signal(true);
		execve(path, cmd_tab, env_tab);
	}
	return (FAILURE);
}

void	exec_fork(t_cmd *cmd, t_cmd *start)
{
	pid_t	pid;

	g_error = 0;
	if (!cmd)
		return ;
	pid = fork();
	if (pid == -1)
		ft_print_error_msg(ERROR_FORK);
	else if (pid == 0)
		exec_child(cmd, start);
	else
		cmd->pid = pid;
}
