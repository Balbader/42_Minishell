/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:51:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/11 17:14:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
/*
void	free_all_tab(char **tab)
{
	int	len;

	len  = -1;
	while (tab[++len] != NULL)
		;
	while (--len >= 0)
		free(tab[len]);
	free(tab);
}
*/
int	split_into_words(t_data *in)
{
	char	**tab;

	tab = sep_cmdline(in->input);
	if (!tab)
		return (FAILURE);
	in->cmd_line = add_all_words_nodes(tab);
	free(tab);
	if (in->cmd_line)
		tokenizer(in->cmd_line);
	else
		return (FAILURE);
	return (SUCCESS);
}
