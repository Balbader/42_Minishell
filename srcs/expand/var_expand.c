/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:15:51 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/13 11:55:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

char	*var_expand(char *str, char **varlst)
{
	char	*new_str;
	char	*var_buffer;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (str[flag])
	{
		while (str[flag] != '$' && ft_isspace(str[flag + 1]) && str[flag])
			flag++;
		new_str = ft_substr(str, i, flag - i);
		i = flag;
		while (!ft_isspace(str[flag]) && str[flag])
			flag++; 
		var_buffer = ft_substr(str, i, flag - i);
		var_buffer = subst_var(var_buffer, varlst);
		new_str = ft_strjoin_free(new_str, var_buffer);
		free(var_buffer);
		i = flag;
	}
	return (new_str);
}
