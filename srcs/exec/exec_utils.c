/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:49:15 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/02 11:21:48 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_arg_to_tab(t_token *arg)
{
	char	**cmd_tab;
	int		arg_len;
	t_token	*head;
	int		i;

	arg_len = get_arg_len(arg);
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
		printf("Error occurred finding path!\n");
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
	t_list	*dump;
	int		i;

	paths = create_path();
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
