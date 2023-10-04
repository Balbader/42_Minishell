/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:33 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/04 17:32:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_by_env_value(char *word)
{
	t_env	*current;
	char	*new_str;

	current = *ft_get_env(0, 0, 0);
	while (current != NULL)
	{
		if (ft_strncmp(word + 1, current->key, ft_strlen(current->key) - 1) == 0)
			break ;
		current = current->next;
	}
	if (current != NULL)
		new_str = ft_strdup(current->value);
	else
		new_str = ft_strdup("");
	return (new_str);
}

char	*replace_var_by_value(char *ptr)
{
	char	*new_str;

	if (ptr[1] == '?' && ft_strlen(ptr) == 2)
	{
		new_str = ft_itoa(g_error);
	}
	else
		new_str = replace_by_env_value(ptr);
	return (new_str);
}

char	**sep_in_dollar_word(char *str)
{
	char	**sep_str;
	int		i;
	int		j;
	int		count;

	count = ((i = 0, j = -1, dollar_word_count(str)));
	sep_str = ft_calloc(count + 1, sizeof(char *));
	if (!sep_str)
		return (NULL);
	while (str[i] && ++j < count)
	{
		while (str[i] != '$' && str[i])
			i++;
		if (*str == '$')
		{
			sep_str[j] = dup_var_word(str);
			i += skip_var_char(str);
		}
		else
			sep_str[j] = dup_str_until(str, i);
		if (i >= (int)ft_strlen(str))
			break ;
		str += i;
		i = 0;
	}
	return (sep_str);
}

char	*expand_var(char *word)
{
	char	**sep_word;
	char	**new_word;
	char	*join_word;
	int		i;

	if (ft_strchr(word, '$') == 0)
		return (word);
	sep_word = sep_in_dollar_word(word);
	if (!sep_word)
		return (NULL);
	new_word = ft_calloc(get_tab_len(sep_word) + 1, sizeof(char *));
	if (!new_word)
		return (NULL);
	i = -1;
	while (sep_word[++i])
	{
		if (ft_strlen(sep_word[i]) > 1 && sep_word[i][0] == '$')
			new_word[i] = replace_var_by_value(sep_word[i]);
		else
			new_word[i] = sep_word[i];
		if (!new_word[i])
			return (free_2_tabs(new_word, sep_word), NULL);
	}
	join_word = ft_join_all_str(new_word);
	ft_free_tabs(sep_word);
	ft_free_tabs(new_word);
	return (/*free_2_tabs(new_word, sep_word), */join_word);
}
/*
char	*expand_var(char *word)
{
	int		i;
	char	**split;
	char	**new_word;
	char	*join_word;

	if (ft_strchr(word, '$') == 0)
		return (word);
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
*/
/*
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
*/
