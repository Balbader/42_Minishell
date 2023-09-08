/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_on.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:11:58 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/05 10:12:03 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	quote_on(const char *input, int index)
{
	int	i;
	bool	simplq_on;
	bool	doublq_on;

	simplq_on = false;
	doublq_on = false;
	i = 0;
	while (i < index)
	{
		if (input[i] == '\'' && input[i + 1] != '\'' && doublq_on == false)
			simplq_on = !simplq_on;
		else if (input[i] == '\"' && simplq_on == false)
			doublq_on = !doublq_on;
		else if (input[i] == '\'' && input[i + 1] == '\'' && simplq_on == false)
			doublq_on = !doublq_on;
		i++;
	}
	return (simplq_on || doublq_on);
}
