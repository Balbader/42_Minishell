/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:49:15 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/27 10:32:10 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_arg_to_tab(t_token *arg)
{
	char	**cmd_tab;
	int		arg_len;
	t_token	*head;
	int		i;

	arg_len = get_execarg_len(arg);
	cmd_tab = ft_calloc(arg_len + 1, sizeof(char *));
	if (!cmd_tab)
		return (NULL);
	head = arg;
	i = -1;
	while (head != NULL && ++i < arg_len)
		cmd_tab[i] = ft_strdup(arg->word);
	cmd_tab[i] = NULL;
	return (cmd_tab);
}

char	*copy_path(char **envp)
{
	int		i;
	char	*path_copy;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_copy = ft_strdup(envp[i] + 5);
			return (path_copy);
		}
		i++;
	}
	return (NULL);
}

char	**create_path(char **envp)
{
	char	*strdup_path;
	char	**split_path;
	char	**comp_path;

	if (envp == NULL)
	{
		ft_putstr_fd("envp error\n", 2);
		exit(127);
	}
	strdup_path = copy_path(envp);
	split_path = ft_split(strdup_path, ':');
	comp_path = loop_joinf(split_path, "/");
	free(strdup_path);
	return (comp_path);
}

char	*init_path(char *cmd, char **envp)
{
	char	**paths;
	char	*individual_path;
	t_list	*dump;
	int		i;

	paths = create_path(envp);
	dump = ft_calloc(1, sizeof(t_list));
	add_str_to_dump(paths, dump);
	i = 0;
	while (paths[i] != 0)
	{
		individual_path = ft_strjoin(paths[i], cmd);
		if (access(individual_path, X_OK) == 0)
		{
			dump_del(dump);
			return (individual_path);
		}
		dump_add(individual_path, dump);
		i++;
	}
	dump_del(dump);
	return (0);
}

char	*expand_heredoc_var(char *line)
{
	char	*new_line;

	new_line = expand_var(line);
	free(line);
	return (new_line);
}
