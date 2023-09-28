/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:20:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 16:48:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_pipe(t_cmd **cmd)
{
	int	fd[2];

	if (pipe(fd) < 0)
		return ;
	(*cmd)->fd[OUT] = fd[OUT];
	(*cmd)->next->fd[IN] = fd[IN];
}

void	close_fdtab(t_cmd *cmd)
{
	if (cmd->fd[IN] != STDIN_FILENO)
		close(cmd->fd[IN]);
	if (cmd->fd[OUT] != STDOUT_FILENO)
		close(cmd->fd[OUT]);
}

void	do_child_wait(int pid)
{
	int	wait;

	waitpid(pid, &wait, 0);
	if (WIFEXITED(wait))
		g_error = WEXITSTATUS(wait);
	else if (WIFSIGNALED(wait))
	{
		g_error = 128 + WTERMSIG(wait);
		error_signal();
	}
}

void	do_process(t_cmd *cmd)
{
	t_cmd	*ptr;

	while (cmd != 0)
	{
		signal(SIGINT, SIG_IGN);//replace by actual fnction
		if (cmd->pid > 0)
			do_child_wait(cmd->pid);
		ft_init_signal(false);
		ptr = cmd;
		cmd = cmd->next;
		if (!ptr->args)
			close_fdtab(ptr);
		ft_del_tokens(ptr->args);
		ft_del_tokens(ptr->rdir);
		free(ptr);
	}
}

void	launch_execution(t_cmd *cmd)
{
	t_cmd	*head;
	bool	error_found;
	int		ret;

	head = cmd;
	while (cmd)
	{
		error_found = false;
		if (cmd->next)
			do_pipe(&cmd);
		if (cmd->rdir != 0)
		{
			ret = exec_rdir(cmd);
			if (ret == -1)
				break ;
			if (ret == FAILURE)
				error_found = true;
		}
		if (!error_found && cmd->args && !ft_run_builtins(cmd->args->word, cmd))
			exec_fork(cmd, head);
		close_fdtab(cmd);
		cmd = cmd->next;
	}
	do_process(head);
}
