/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:15:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/13 13:25:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

char	*var_expand(char *str,  t_list *varlst)
{
	char	*new_str;
	char	**split_str;
	int		i;

	split_str = ft_split(str, '$');
	if (!split_str)
		return (NULL);
	i = 0;
	while (split_str[i])
	{
		add_var_to_str(split_str, i, varlst);
		
	}
	return (new_str);
}
