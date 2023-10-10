/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:49:15 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/10 11:32:18 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_cmd_tab_len(char ***tab)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			len++;
	}
	return (len);
}

char	**join_all_2str_tabs(char ***cmd_tab)
{
	char	**final_tab;
	int		final_len;
	int		i;
	int		j;
	int		k;

	i = -1;
	final_len = ft_get_cmd_tab_len(cmd_tab);
	final_tab = ft_calloc(final_len + 1, sizeof(char *));
	if (!final_tab)
		return (NULL);
	i = -1;
	k = 0;
	while (cmd_tab[++i] && k < final_len)
	{
		j = -1;
		while (cmd_tab[i][++j])
		{
			final_tab[k] = ft_strdup(cmd_tab[i][j]);
			if (!final_tab[k])
				return (ft_free_tabs(final_tab), NULL);
		k++;
		}
	}
	return (final_tab);
}

void	free_big_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i])
		{
			ft_free_tabs(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
}

char	**convert_arg_to_tab(t_token *arg)
{
	char	***cmd_tab;
	char	**final_tab;
	int		arg_len;
	t_token	*head;
	int		i;

	arg_len = get_arg_len(arg);
	cmd_tab = ft_calloc(arg_len + 1, sizeof(char **));
	if (!cmd_tab)
		return (NULL);
	head = arg;
	i = -1;
	while (head != NULL && ++i < arg_len)
	{
		cmd_tab[i] = ft_split(head->word, ' ');
		if (!cmd_tab[i])
			return (free_big_tab(cmd_tab), NULL);
		head = head->next;
	}
	final_tab = join_all_2str_tabs(cmd_tab);
	return (free_big_tab(cmd_tab), final_tab);
}
