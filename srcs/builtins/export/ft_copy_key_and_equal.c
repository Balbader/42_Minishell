/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_key_and_equal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:49:31 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/03 11:49:32 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_equal_pos(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (i + 1);
		++i;
	}
	return (0);
}

char	*ft_copy_key_and_equal(char *var, char *new_key)
{
	int	equal_pos;
	int	i;

	equal_pos = ft_get_equal_pos(var);
	new_key = (char *)malloc(sizeof(char) * (equal_pos + 1));
	if (!new_key)
		return (NULL);
	i = 0;
	while (i < equal_pos)
	{
		new_key[i] = var[i];
		++i;
	}
	new_key[i] = '\0';
	return (new_key);
}
