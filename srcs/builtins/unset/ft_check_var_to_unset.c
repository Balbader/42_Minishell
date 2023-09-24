/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_var_to_unset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:05:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 14:05:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_var_to_unset(char *var)
{
	while (*var)
		{
			if (!ft_is_alpha(*var) && !ft_isdigit(*var) && *var != '_')
				return (false);
			++var;
		}
	return (true);
}
