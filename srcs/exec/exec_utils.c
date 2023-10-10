/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:49:15 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/10 11:00:35 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**join_all_2str_tabs(char ***cmd_tab)
{
	char	**final_tab;
	int		final_len;
	int		i;
	int		j;
	int		k;

	i = -1;
	final_len = 0;
	while (cmd_tab[++i])
	{
		j = -1;
		while (cmd_tab[i][++j])
			final_len++;
	}
	printf("---------------------> final_len : %d\n", final_len);
	final_tab = ft_calloc(final_len + 1, sizeof(char *));
	if (!final_tab)
		return (NULL);
	i = -1;
	k = 0;
	while (cmd_tab[++i] && k < final_len)
	{
		j = -1;
		while (cmd_tab[i][++j])
		{
			final_tab[k] = ft_strdup(cmd_tab[i][j]);
			if (!final_tab[k])
				return (ft_free_tabs(final_tab), NULL);
		k++;
		}
	}
	return (final_tab);
}

void	free_big_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i])
		{
			ft_free_tabs(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
}

char	**convert_arg_to_tab(t_token *arg)
{
	char	***cmd_tab;
	char	**final_tab;
	int		arg_len;
	t_token	*head;
	int		i;

	arg_len = get_arg_len(arg);
	printf("---------------------> arg_len : %d\n", arg_len);
	cmd_tab = ft_calloc(arg_len + 1, sizeof(char **));
	if (!cmd_tab)
		return (NULL);
	head = arg;
	i = -1;
	while (head != NULL && ++i < arg_len)
	{
		cmd_tab[i] = ft_split(head->word, ' ');
		if (!cmd_tab[i])
			return (free_big_tab(cmd_tab), NULL);
		head = head->next;
	}
	final_tab = join_all_2str_tabs(cmd_tab);
	return (final_tab);
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
