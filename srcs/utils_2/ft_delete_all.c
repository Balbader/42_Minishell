/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:27:18 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 18:27:20 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_delete_all(t_token **node)
{
	t_token	*tmp;

	while ((*node))
	{
		tmp = (*node);
		free((*node)->word);
		(*node) = (*node)->next;
		free(tmp);
	}
	node = NULL;
	return (NULL);
}
