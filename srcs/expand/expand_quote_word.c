/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:46:28 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 16:35:44 by ftuernal         ###   ########.fr       */
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

/*
int	skip_quote_char(char *str, int i)
{
	while (quote_on(str, i) == true)
		i++;
	return (i);
}
*/
char	*dup_quote_word(char *word, t_quote qtype)
{
	int		lim;
	char	*quote_word;

	lim = 1;
	while (word[lim] && quote_on(word, lim) == qtype)
		lim++;
	quote_word = dup_str_until(word, lim);
	return (quote_word);
}

int		count_quote_words(char *word)
{
	int		count;
	int		i;
	bool	quote_flag;

	count = 1;
	i = 0;
	quote_flag = quote_on(word, i);
	while (word[i])
	{
		if (quote_on(word, i) != quote_flag)
		{
			quote_flag = !quote_flag;
			count++;
		}
		i++;
	}
	return (count);
}

int	set_start_qword(char *word, int i)
{
	int	start;

	start = i;
	while (word[start])
	{
		if (quote_on(word, start) == true)
		{
			if (quote_on(word, start + 1) == true)
				return (start + 1);
		}
		else if (word[start] != '\"' || word[start] != '\'')
			break ;
		start++;
	}
	return (start);
}

int	set_end_qword(char *word, int start)
{
	int	end;

	end = start + 1;
	while (word[end])
	{
		if (quote_on(word, end) == true)
		{
			if (quote_on(word, end + 1) == false)
				return (end + 1);
		}
		else if (word[end] == '\"' || word[end] == '\'')
			break ;
		end++;
	}
	return (end);
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
//printf("sep_str[0] = %s | sep_str[1] = %s\n", sep_str[0], sep_str[1]);
	return (sep_str);
}

char	*expand_quote_var(char *str, t_quote quote_type)
{
	char	*sin_quote;
	char	*var_expand;


	if (quote_type == SQUOTE)
		return (ft_strtrim(str, "\"\'"));
	var_expand = expand_var(str);
printf("var_expanded str = %s\n", var_expand);
	if (var_expand)
	{
		if (quote_type == DQUOTE)
		{
			sin_quote = ft_strtrim(var_expand, "\'\"");
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

print_all_words(cmd_line);
	sep_word = sep_quote_word(word);
	if (!sep_word)
		return (FAILURE);
//print_tab(sep_word);
	sep_exp = ft_calloc(get_tab_len(sep_word) + 1, sizeof(char *));
	if (!sep_exp)
		return (ft_free_tabs(sep_word), FAILURE);
	i = -1;
	while (sep_word[++i])
	{
		if (set_quote_type(sep_word[i][0]) != SQUOTE)
			sep_exp[i] = expand_quote_var(sep_word[i], set_quote_type(sep_word[i][0]));
		else
			sep_exp[i] = quote_remove(sep_word[i]);
		if (!sep_exp[i])
			return (free_2_tabs(sep_word, sep_exp), FAILURE);
	}
	new_word = ft_join_all_str(sep_exp);
	free_2_tabs(sep_word, sep_exp);
	return (substitute_word(cmd_line, new_word), SUCCESS);
}
/************************************************************************************************
int	expand_quote_word(t_token *cmd_line, char *word)
{
	char	*tmp;
	char	*dollarfree_str;
	t_quote	quote_type;

	quote_type = set_quote_type(word[0]);
	tmp = quote_remove(word);
	if (quote_type == DQUOTE && ft_strchr(tmp, '$') != 0)
	{
		dollarfree_str = expand_var(tmp);
		if (!dollarfree_str)
			return (free(tmp), FAILURE);
		substitute_word(cmd_line, dollarfree_str);
	}
	else
		return (substitute_word(cmd_line, tmp), SUCCESS);
	free(tmp);
	return (SUCCESS);
}
********************************************************************************************/

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
