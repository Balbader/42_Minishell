/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key_section.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:58:40 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/28 18:58:42 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_key_section(char *var, char *key)
{
	int	key_len;
	int	i;

	key_len = ft_get_key_len(var);
	key = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (i < key_len - 1)
	{
		key[i] = var[i];
		++i;
	}
	key[i] = '\0';
	return (key);
}
