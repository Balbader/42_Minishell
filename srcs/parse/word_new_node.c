/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:17:10 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/05 16:56:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_token	*word_new_node(char *line, int start, int len)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (0);
	new->word = ft_substr(line, start, len);
	if (!new->word)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
