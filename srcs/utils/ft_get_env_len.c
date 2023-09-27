/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:44:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 11:44:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * returns the total amount of elements is a 2D array
*/

int	ft_get_env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		++i;
	return (i);
}
