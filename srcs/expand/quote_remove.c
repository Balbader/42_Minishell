/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:59:34 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/13 11:15:02 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

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
	// debug
	if (quote_type == NOQUOTE)
		printf("Caution: you let an invalid string enter this function\n");
	//endof debug
	i = -1;
	j = 0;
	while (str[++i] && j < len)
	{
		if (is_quote(str[i]) == 1 && set_quote_type(str[i]) == quote_type)
			i += 1;
		new_str[j] = str[i];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char	*str = "\'i need to \"\"\"\"\"know what quote to remove_\'";
	char	*new_str;

	new_str = quote_remove(str);
	printf("ORIGINAL STR\n---%s---\n", str);
	printf("NEW STR == ---%s---\n", new_str);
	free(new_str);
}
*/
