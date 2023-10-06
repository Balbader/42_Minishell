/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:37:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/06 15:54:39 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_var_char(char c)
{
	if (isalnum(c) != 0 || c == '_' || c == '?' || c == '$')
		return (true);
	return (false);
}

int	dollar_word_count(char *str)
{
	int			i;
	int			count;
	int			flag;

	flag = false;
	i = 0;
	if (*str == '$')
		count = 0;
	else
		count = 1;
	while (str[i])
	{
		if (str[i] == '$')
		{
			flag = true;
			count++;
		}
		else if (flag == true && is_var_char(str[i]) == false)
		{
			flag = false;
			count++;
		}
		i++;
	}
	return (count);
}

char	*dup_str_until(char *str, int lim)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_calloc(lim + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i] && i < lim)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

char	*dup_var_word(char *str)
{
	int		lim;
	char	*var_str;

	lim = 1;
	while (str[lim] && is_var_char(str[lim]) == true)
		lim++;
	var_str = dup_str_until(str, lim);
	return (var_str);
}

int	skip_var_char(char *str)
{
	int	i;

	i = 0;
	while (is_var_char(str[i]) == true && str[i])
		i++;
	return (i);
}
