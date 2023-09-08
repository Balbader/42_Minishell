/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback_word_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:50:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/05 16:45:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	addback_word_node(t_token **words, t_token *new)
{
	t_token	*last_ad;

	if (!(*words)->word)
	{
		*words = new;
		return ;
	}
	last_ad = goto_last_word(*words);
	last_ad->next = new;
}
