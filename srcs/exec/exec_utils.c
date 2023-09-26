/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:49:15 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/25 16:50:39 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_arg_to_tab(t_token *arg)
{
	char	**cmd_tab;
	int		arg_len;
	t_token	*head;
	int		i;

	arg_len = get_execarg_len(arg);
	cmd_tab = ft_calloc(arg_len + 1, sizeof(char *));
	if (!cmd_tab)
		return (NULL);
	head = arg;
	i = -1;
	while (head != NULL && ++i < arg_len)
		cmd_tab[i] = ft_strdup(arg->word);
	cmd_tab[i] = NULL;
	return (cmd_tab);
}
