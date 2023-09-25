/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:43:18 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/25 17:43:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_child(t_cmd *cmd, t_cmd *start)
{
	char	**env_tab;
	char	**cmd_tab;
	char	*path;

	cmd_tab = convert_arg_to_tab(cmd->arg);
	env_tab = ft_convert_env_to_tab(*get_env(0)); 
	if (!cmd_tab || !env_tab)
	{
		free_2_tabs(cmd_tab, env_tab);
		return (EXEC_FAILURE);
	}
	path = init_path(cmd_tab[0], env_tab);//this is shady..slim shady almost :-Zif (cmd->fd[IN] != STDIN_FILENO)
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
	//free cmd struct
	if (path)
	{
		siginit(true);
		execve(path, cmd_tab, env_tab);
	}
	return (FAILURE);
}
