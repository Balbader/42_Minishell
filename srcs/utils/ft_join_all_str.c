/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_all_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:43:46 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 12:16:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_all_str(char **split)
{
	int		i;
	char	*joined_str;

	i = -1;
	joined_str = ft_calloc(1, sizeof(char));
	if (!joined_str)
		return (NULL);
	while (split[++i])
	{
		joined_str = join_free(joined_str, split[i], joined_str);
		if (!joined_str)
			return (NULL);
	}
	return (joined_str);
}

