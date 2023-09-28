/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:04:27 by ftuernal          #+#    #+#             */
/*   Updated: 2023/08/31 16:23:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_cmd(t_data *in, t_exec *exec)
{
	exec->cmd = ft_split(in->input, ' ');
	if (!exec->cmd)
		return (manage_err(CMD_ALLOC, in, exec));
	exec->path = init_path(exec->cmd[0], in->env); //replace by path management
	printf("PATH == %s\n", exec->path);
	return (0);
}

void	exec_cmd(t_data *in, t_exec *exec)
{
	int		pid;

	init_cmd(in, exec);
	pid = fork();
	if (pid == 0)
	{
		if (ft_strchr(exec->cmd[0], '/'))
			execve(exec->cmd[0], exec->cmd + 1, NULL);
		else
			execve(exec->path, exec->cmd, in->env);
	wait(NULL);
}
