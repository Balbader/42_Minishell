/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:59:47 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/05 08:53:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_rdir_rin(t_cmd *cmd)
{
	int		fd;
	char	*name;

	if (!cmd->rdir->next)
		ft_print_error_msg(ERROR_RED);
	name = cmd->rdir->next->word;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror(name);
		return (FAILURE);
	}
	if (cmd->fd[IN] != 0)
	{
		dup2(fd, cmd->fd[IN]);
		close(cmd->fd[IN]);
	}
	cmd->fd[IN] = fd;
	return (SUCCESS);
}

int	exec_rdir_rout(t_cmd *cmd)
{
	int		fd;
	char	*name;

	if (!cmd->rdir->next)
		ft_print_error_msg(ERROR_RED);
	name = cmd->rdir->next->word;
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(name);
		return (FAILURE);
	}
	if (cmd->fd[OUT] != 1)
	{
		dup2(fd, cmd->fd[OUT]);
		close(cmd->fd[OUT]);
	}
	cmd->fd[OUT] = fd;
	return (SUCCESS);
}

int	exec_rdir_append(t_cmd *cmd)
{
	int		fd;
	char	*name;

	if (!cmd->rdir->next)
		ft_print_error_msg(ERROR_RED);
	name = cmd->rdir->next->word;
	fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(name);
		return (FAILURE);
	}
	if (cmd->fd[OUT] != 1)
	{
		dup2(fd, cmd->fd[OUT]);
		close(cmd->fd[OUT]);
	}
	cmd->fd[OUT] = fd;
	return (SUCCESS);
}

int	exec_rdir(t_cmd *cmd)
{
	t_token	*rdir_save;
	int		ret;

	rdir_save = cmd->rdir;
	while (cmd->rdir != 0)
	{
		if (cmd->rdir->type == R_IN)
			ret = exec_rdir_rin(cmd);
		else if (cmd->rdir->type == R_OUT)
			ret = exec_rdir_rout(cmd);
		else if (cmd->rdir->type == APPEND)
			ret = exec_rdir_append(cmd);
		else if (cmd->rdir->type == HEREDOC)
			return (exec_rdir_heredoc(cmd));
		if (ret == FAILURE)
			return (g_error = 1, FAILURE);
		cmd->rdir = cmd->rdir->next;
	}
	cmd->rdir = rdir_save;
	return (SUCCESS);
}
