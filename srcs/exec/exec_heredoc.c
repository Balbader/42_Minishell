/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:38:36 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 20:19:02 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_heredoc_failure(int fd_save)
{
	dup2(fd_save, 0);
	ft_init_signal(false);
	close(fd_save);
	write(STDOUT_FILENO, "\n", 1);
	g_error = 130;
}

int	heredoc_no_expand(t_token *rdir)
{
	char	*limit;
	char	*line;
	int		fd;

	limit = NULL;
	fd = create_heredoc(1);
	if (fd < 0)
		return (perror(limit), fd);
	if (rdir->next->type == LIMITOR)
		limit = ft_strtrim(rdir->next->word, "\'\"");
	while (1)
	{
		line = readline(">>");
		if (line == NULL || !limit)
			break ;
		if (ft_strcmp(limit, line) == 0)
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	return (free(limit), fd);
}

int	heredoc_expand(t_token *rdir)
{
	char	*limit;
	char	*line;
	int		fd;

	fd = create_heredoc(1);
	limit = NULL;
	if (fd < 0)
		return (perror(limit), fd);
	if (rdir->next->type == LIMITOR)
		limit = ft_strdup(rdir->next->word);
	while (1)
	{
		line = readline(">>");
		if (line == 0)
			break ;
		if (ft_strcmp(line, limit) == 0)
			break ;
		if (ft_strchr(line, '$') != 0)
			line = expand_heredoc_var(line);
		if (line)
			ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		free(line);
	}
	return (free(limit), fd);
}

int	create_heredoc(int type)
{
	int	fd_ret;

	if (type)
	{
		fd_ret = open("/tmp/.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_ret < 0)
			fd_ret = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		fd_ret = open("/tmp/.heredoc", O_RDONLY | O_CREAT, 0644);
		if (fd_ret < 0)
			fd_ret = open(".heredoc", O_RDONLY | O_CREAT, 0644);
	}
	return (fd_ret);
}

int	exec_rdir_heredoc(t_cmd *cmd)
{
	int	fd_save;
	int	fd;

	fd_save = dup(STDIN_FILENO);
	signal(SIGINT, &ft_sig_heredoc);
	if (is_quote_heredoc(cmd->rdir) == true)
		fd = heredoc_no_expand(cmd->rdir);
	else
		fd = heredoc_expand(cmd->rdir);
	if (fd < 0)
		return (FAILURE);
	close(fd);
	if (g_error == 128)
	{
		dup2(fd_save, 0);
		ft_init_signal(false);
		return ((close(fd_save), write(STDOUT_FILENO, "\n", 1),
				g_error = 130, -1));
	}
	fd = ((close(fd_save), ft_init_signal(false), create_heredoc(0)));
	if (cmd->fd[IN] != STDIN_FILENO)
	{
		dup2(fd, cmd->fd[IN]);
		close(cmd->fd[IN]);
	}
	return (cmd->fd[IN] = fd, SUCCESS);
}
