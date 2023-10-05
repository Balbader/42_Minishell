/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:46:28 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/05 11:42:30 by ftuernal         ###   ########.fr       */
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


/************************************************************************************************
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

char	*dup_quote_word(word)
{
	int		lim;
	char	*quote_word;

	lim = 1;
	while (word[lim] && quote_on(word, lim) == true)
		lim++;
	quote_word = dup_str_until(word, lim);
	return (quote_word);
}

char	**sep_quote_word(char *word)
{
	char	*sep_str;
	int		i;
	int		j;
	int		count;

	count = ((i = 0, j = -1, count_quote_words(word)));
	sep_str = ft_calloc(count + 1, sizeof(char *));
	if (!sep_str)
		return (NULL);
	while (++j < count && word[i])
	{
		while (quote_on(word, i) == false)
			i++;
		if (quote_on(word, i) == true)
			sep_str[j] = ((i += skip_quote_char(word), dup_quote_word(word)));
		else
			sep_str[j] = dup_str_until(str, i);
		if (i >= (int)ft_strlen(str))
			break ;
		str += i;
		i = 0;
	}
	return (sep_str);
}

char	*expand_quote_var(char *str, t_quote quote_type)
{
	char	*sin_quote;
	char	*var_expand;

	var_expand = expand_var(str);
	if (var_expand)
	{
		if (quote_type == DQUOTE)
		{
			sin_quote = quote_remove(var_expand);
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
	sep_exp = ft_calloc(get_len(sep_word) + 1, sizeof(char *));
	if (!sep_exp)
		return (ft_free_tabs(sep_word), FAILURE);
	i = -1;
	while (sep_word[++i])
	{
		if (set_quote_type(sep_word[i][0]) != SQUOTE)
			sep_exp[i] = expand_quote_var(sep_word[i]);
		else
			sep_exp[i] = quote_remove(sep_word[i]);
		if (!sep_exp[i])
			return (free_2_tabs(sep_word, sep_exp));
	}
	new_word = join_all_str(sep_exp);
	free_2_tabs(sep_word, sep_exp);
	return (substitute_word(cmd_line, new_word), SUCCESS);
///////////////CORRECTION EXPAND_QUOTE_WORD EN COURS TO BE TESTED TODO TEST THE COMMENTED CODE
********************************************************************************************/
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
