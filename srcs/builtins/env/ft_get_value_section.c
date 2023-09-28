/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_section.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:58:47 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/28 18:58:50 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value_section(char *var, char *value)
{
	int	value_len;
	int i;
	int j;

	value_len = ft_get_value_len(var);
	value = (char *)malloc(sizeof(char) * (value_len + 1));
	if (!value)
		return (NULL); 
	i = ft_get_key_len(var) + 1;
	j = 0;
	while (var[i])
	{
		value[j] = var[i];
		++j;
		++i;
	}
	value[j] = '\0';
	return (value);
}
