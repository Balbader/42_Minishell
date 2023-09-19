/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:59:34 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/19 17:41:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quote	set_quote_type(char quote)
{
	if (quote == '\'')
		return (SQUOTE);
	else if (quote == '\"')
		return (DQUOTE);
	else
		return (NOQUOTE);
}

int		is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

char	*quote_remove(char *str)
{
	char	*new_str;
	int		i;
	int		j;
	t_quote	quote_type;
	int		len;

	len = ft_strlen(str) - 1;
	new_str = ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	quote_type = set_quote_type(str[0]);
	i = -1;
	j = 0;
	while (str[++i] && i < len && j < len)
	{
		if (is_quote(str[i]) == 1 && set_quote_type(str[i]) == quote_type)
			i += 1;
		new_str[j] = str[i];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
