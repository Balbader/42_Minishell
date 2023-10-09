/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:33 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 16:45:53 by ftuernal         ###   ########.fr       */
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

int	set_dollar_end(char *str, int start)
{
	int	end;

	end = start + 1;
	if (start == '$')
	{
		while (str[end] && (str[end] != '_' || ft_isalnum(str[end]) != 0 || str[end] != '?'))
			end++;
	}
	else
	{
		while (str[end])
		{
			if (str[end] == ' ' || str[end] == '$')
				return (end);
			end++;
		}
	}
	return (end);
}

char	**sep_in_dollar_word(char *str)
{
	char	**sep_str;
	int		start;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = -1;
	sep_str = ft_calloc(dollar_word_count(str) + 1, sizeof(char *));
	if (!sep_str)
		return (NULL);
	while (str[i] && ++j < dollar_word_count(str))
	{
		start = i;
		end = set_dollar_end(str, start);
		sep_str[j] = ft_substr(str, start, end - start);
		while (i < end && str[i])
			i++;
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
		return (ft_strdup(word));
	sep_word = sep_in_dollar_word(word);
	if (!sep_word)
		return (NULL);
printf("SEP DOLLAR TAB ==\n");
print_tab(sep_word);
	new_word = ft_calloc(get_tab_len(sep_word) + 1, sizeof(char *));
	if (!new_word)
		return (NULL);
	i = -1;
	while (sep_word[++i])
	{
		if (ft_strlen(sep_word[i]) > 1 && sep_word[i][0] == '$')
			new_word[i] = replace_var_by_value(sep_word[i]);
		else
			new_word[i] = ft_strdup(sep_word[i]);
		if (!new_word[i])
			return (free_2_tabs(new_word, sep_word), NULL);
	}
	join_word = ft_join_all_str(new_word);
	return (free_2_tabs(new_word, sep_word), join_word);
}
