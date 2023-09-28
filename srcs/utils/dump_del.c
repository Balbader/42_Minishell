/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:45:17 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 16:35:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dump_del(t_list *garbage)
{
	if (garbage == NULL)
		return ;
	else
	{
		dump_del(garbage->next);
		free(garbage->content);
		free(garbage);
	}
}
