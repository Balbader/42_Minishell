/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:27:36 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 14:27:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_str_is_digit(char **str)
{
	int		tr;
	char	*tmp;

	tr = false;
	tmp = *str;
	*str = ft_remove_quotes(*str);
	free(tmp);
	tmp = *str;
	while (*tmp)
	{
		if (ft_isdigit(*tmp))
			tr = true;
		++tmp;
	}
	if (!tr)
		return (false);
	return (true);
}
