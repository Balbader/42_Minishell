/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:45:17 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 17:14:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

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
