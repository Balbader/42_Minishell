/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:43:18 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 20:24:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_everything(char *path, char **env_tab, char **cmd_tab)
{
	free_2_tabs(env_tab,cmd_tab);
	free(path);
	ft_del_env();
	perror("");
}

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
		free_everything(path, env_tab, cmd_tab);
	}
	return (exit(g_error), FAILURE);
}

void	exec_fork(t_cmd *cmd, t_cmd *start)
{
	pid_t	pid;

	g_error = 0;
	if (!cmd)
		return ;

print_all_words(cmd->args);
	pid = fork();
	if (pid == -1)
		ft_print_error_msg(ERROR_FORK);
	else if (pid == 0)
		exec_child(cmd, start);
	else
		cmd->pid = pid;
}
