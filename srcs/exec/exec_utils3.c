/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:58:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/10 12:58:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_path(void)
{
	t_env	*cur_env;
	t_env	*ptr;

	cur_env = *ft_get_env(0, 0, 0);
	if (!cur_env)
		return (NULL);
	ptr = cur_env;
	while (ptr != 0)
	{
		if (ft_strncmp(ptr->key, "PATH", 4) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

char	**create_path(void)
{
	char	*path_cpy;
	char	**split_path;
	char	**comp_path;

	path_cpy = copy_path();
	if (!path_cpy)
	{
		ft_putstr_fd("Error occurred finding path!\n", 2);
		return (NULL);
	}
	split_path = ft_split(path_cpy, ':');
	comp_path = loop_joinf(split_path, "/");
	return (comp_path);
}

char	*init_path(char *cmd)
{
	char	**paths;
	char	*individual_path;
	int		i;

	if (ft_strchr(cmd, '/') != 0)
		return (cmd);
	paths = create_path();
	individual_path = NULL;
	i = 0;
	while (paths[i] != 0)
	{
		if (individual_path != NULL)
		{
			free(individual_path);
			individual_path = NULL;
		}
		individual_path = ft_strjoin(paths[i], cmd);
		if (access(individual_path, X_OK) == 0)
		{
			return (ft_free_tabs(paths), individual_path);
		}
		i++;
	}
	return (ft_free_tabs(paths), individual_path);
}

char	*expand_heredoc_var(char *line)
{
	char	*new_line;

	new_line = expand_var(line);
	free(line);
	return (new_line);
}

void	ft_del_t_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

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
