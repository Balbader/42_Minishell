/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:33 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/03 12:02:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_by_last_ret(char *word)
{
	char	*new_str;
	int		last_ret;
	char	*ascii_ret;

	new_str = ft_strdup(word + 1);
	if (!new_str)
		return (NULL);
	last_ret = g_error;
	ascii_ret = ft_itoa(last_ret);
	if (!ascii_ret)
		return (free(new_str), NULL);
	new_str = join_free(ascii_ret, new_str, new_str);
	free(ascii_ret);
	return (new_str);
}

char	*dup_word_without_envkey(char *word)
{
	char	*new_word;
	int		i;
	int		j;
	int		new_word_len;

	i = 0;
	while (word[i] && ft_isspace(word[i]) == 0)
		i++;
	new_word_len = ft_strlen(word) - i;
	new_word = ft_calloc(new_word_len + 1, sizeof(char));
	if (!new_word)
		return (NULL);
	j = 0;
	while (word[i])
	{
		new_word[j] = word[i];
		j++;
		i++;
	}
	new_word[j] = '\0';
	return (new_word);
}

char	*replace_by_env_value(char *word)
{
	t_env	*current;
	char	*new_str;

	current = *ft_get_env(0, 0, 0);
	while (current != NULL)
	{
		if (ft_strncmp(word, current->key, ft_strlen(current->key) - 1) == 0)
			break ;
		current = current->next;
	}
	new_str = dup_word_without_envkey(word);
	if (!new_str)
		return (NULL);
	if (current)
		new_str = join_free(current->value, new_str, new_str);
	return (new_str);
}

char	*replace_var_by_value(char *ptr)
{
	char	*new_str;
	int		i;

	i = 0;
	if (ptr[i] == '?')
	{
		new_str = replace_by_last_ret(ptr);
		if (!new_str)
			return (NULL);
		ptr += 1;
	}
	else
		new_str = replace_by_env_value(ptr);
	return (new_str);
}

char	*relace_var_by_value(char *str, int i)
{
	
}

char	*expand_var(char *word)
{
	int		start;
	int		end;
	char	**split;
	char	**new_word;
	char	*join_word;

	if (ft_strchr(word, '$') == 0)
		return (word);
	start = -1;
	while (word[++start])
	{
		if (word[start] == '$')
		{
			end = start;
			while (ft_isspace(word[start] ==))
		}
	}







	split = ft_split(word, '$');
	if (!split)
		return (NULL);
	new_word = ft_calloc(get_tab_len(split) + 1, sizeof(char *));
	if (!new_word)
		return (NULL);
	i = -1;
	while (split[++i])
	{
		if (ft_isspace((*split)[i]) != 0 || (*split)[i] == '\0')
			new_word[i] = ft_strjoin("$", split[i]);
		else if (ft_isspace((*split)[i]) == 0)
			new_word[i] = replace_var_by_value(split[i]);
		if (!new_word[i])
			return (free_2_tabs(new_word, split), NULL);
	}
	join_word = ft_join_all_str(new_word);
	return (free_2_tabs(new_word, split), join_word);
}
