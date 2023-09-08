/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_parse_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:59:11 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/06 11:01:16 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	alloc_parse_struct(t_data *in)
{
	in->cmd_line = ft_calloc(1, sizeof(t_cmdlst));
	if (!in->cmd_line)
		return (FAILURE);
	in->cmd_line->line = ft_calloc(1, sizeof(char));
	if (!in->cmd_line->line)
		return (FAILURE);
	return (SUCCESS);
}
