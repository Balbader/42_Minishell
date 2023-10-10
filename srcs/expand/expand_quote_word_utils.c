/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_word_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:13:53 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/10 13:13:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quote_words(char *word)
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
