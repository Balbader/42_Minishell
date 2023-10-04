/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:43:18 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/02 18:32:35 by ftuernal         ###   ########.fr       */
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
	path = init_path(cmd_tab[0]);
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
	ft_del_t_cmd(start);
	if (path)
	{
		ft_init_signal(true);
		execve(path, cmd_tab, env_tab);
		perror("");
	}
	return (exit(EXIT_FAILURE), FAILURE);
}

void	trim_path(t_token **args)
{
	char	*trim_path;

	trim_path = ft_strtrim((*args)->word, " ");
	if (!trim_path)
	{
		ft_putstr_fd("Error with trimming path\n", STDERR_FILENO);
		return ;
	}
	free((*args)->word);
	(*args)->word = NULL;
	(*args)->word = trim_path;
}

void	exec_fork(t_cmd *cmd, t_cmd *start)
{
	pid_t	pid;

	g_error = 0;
	if (!cmd)
		return ;
	trim_path(&cmd->args);
	pid = fork();
	if (pid == -1)
		ft_print_error_msg(ERROR_FORK);
	else if (pid == 0)
		exec_child(cmd, start);
	else
		cmd->pid = pid;
}
