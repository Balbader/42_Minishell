/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:09:10 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 13:09:11 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare_keys(char *key, char *key_cpy)
{
	int	i;

	i = 0;
	// if (!key || !key_cpy)
	// {
	// 	printf("There is a problem with one of the keys.\n");
	// 	return(0);
	// }
	while (key[i] == key_cpy[i] && key[i] && key_cpy[i])
		++i;
	return (key[i] - key_cpy[i]);
}
