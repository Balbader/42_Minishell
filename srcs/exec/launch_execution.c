/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:20:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 18:57:31 by ftuernal         ###   ########.fr       */
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
		ft_print_sig_error();
	}
}

void	do_process(t_cmd *cmd)
{
	t_cmd	*ptr;

	ptr = cmd;
	while (cmd != 0)
	{
		signal(SIGINT, SIG_IGN);
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

void	ft_del_t_cmd(t_cmd *cmd)
{
	t_cmd *tmp;

	while (cmd)
	{
		tmp = cmd->next;
		ft_del_tokens(cmd->args);
		ft_del_tokens(cmd->rdir);
		if (cmd->fd[IN] != STDIN_FILENO)
			close(cmd->fd[IN]);
		if (cmd->fd[OUT] != STDOUT_FILENO)
			close(cmd->fd[OUT]);
		free(cmd);
		cmd = tmp;
	}
}

void	launch_execution(t_cmd *cmd)
{
	t_cmd	*ptr;
	bool	error_found;
	int		ret;

	ptr = cmd;
	while (ptr)
	{
		error_found = false;
		if (ptr->next)
			do_pipe(&ptr);
		if (ptr->rdir != 0)
		{
			ret = exec_rdir(ptr);
			if (ret == -1)
				break ;
			if (ret == FAILURE)
				error_found = true;
		}
		if (!error_found && ptr->args && !ft_run_builtins(ptr->args->word, cmd))
			exec_fork(ptr, cmd);
		close_fdtab(ptr);
		ptr = ptr->next;
	}
	do_process(cmd);
}
