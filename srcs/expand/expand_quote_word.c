/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:46:28 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 20:06:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	substitute_word(t_token *cmd_line, char *substitute)
{
	free(cmd_line->word);
	cmd_line->word = NULL;
	cmd_line->word = ft_strdup(substitute);
	free(substitute);
}

char	**sep_quote_word(char *word)
{
	int		start;
	int		end;
	char	**sep_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (word[0] == '$' && (word[1] == '\'' || word[1] == '\"'))
		word += 1;
	sep_str = ft_calloc((count_quote_words(word) + 1), sizeof(char *));
	if (!sep_str)
		return (NULL);
	while (j < count_quote_words(word) && word[i])
	{
		start = set_start_qword(word, i);
		end = set_end_qword(word, start);
		sep_str[j] = ft_substr(word, start, end - start);
		while (i < end && word[i])
			i++;
		j++;
	}
	return (sep_str);
}

char	*expand_quote_var(char *str, t_quote quote_type)
{
	char	*sin_quote;
	char	*var_expand;

	if (quote_type == SQUOTE)
		return (ft_strtrim(str, "\'"));
	var_expand = expand_var(str);
	if (var_expand)
	{
		if (quote_type == DQUOTE)
		{
			sin_quote = ft_strtrim(var_expand, "\"");
			return (free(var_expand), sin_quote);
		}
		else
			return (var_expand);
	}
	return (NULL);
}

int	expand_quote_word(t_token *cmd_line, char *word)
{
	char	**sep_word;
	char	**sep_exp;
	char	*new_word;
	int		i;

	sep_word = sep_quote_word(word);
	if (!sep_word)
		return (FAILURE);
	sep_exp = ft_calloc(get_tab_len(sep_word) + 1, sizeof(char *));
	if (!sep_exp)
		return (ft_free_tabs(sep_word), FAILURE);
	i = -1;
	while (sep_word[++i])
	{
		if (set_quote_type(sep_word[i][0]) != SQUOTE)
			sep_exp[i] = expand_quote_var(sep_word[i],
					set_quote_type(sep_word[i][0]));
		else
			sep_exp[i] = quote_remove(sep_word[i]);
		if (!sep_exp[i])
			return (free_2_tabs(sep_word, sep_exp), FAILURE);
	}
	new_word = ft_join_all_str(sep_exp);
	free_2_tabs(sep_word, sep_exp);
	return (substitute_word(cmd_line, new_word), SUCCESS);
}

int	expand_noquote_word(t_token *cmd_line, char *word)
{
	char	*tmp;

	if (ft_strchr(word, '$') != 0)
	{
		tmp = expand_var(word);
		if (!tmp)
			return (FAILURE);
	}
	else
		return (SUCCESS);
	substitute_word(cmd_line, tmp);
	return (SUCCESS);
}
