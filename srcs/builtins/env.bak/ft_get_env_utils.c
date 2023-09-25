/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 08:45:54 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/16 08:45:56 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare_before_equals(char *env, char *find)
{
	if (!find)
		return (false);
	if (!find)
		return (false);
	while (*find && *env && *env != '=' && *find != '=' && *env == *find)
	{
		env++;
		find++;
	}
	if (*env == '=' && (!*find || *find == '='))
		return (true);
	return (false);
}
