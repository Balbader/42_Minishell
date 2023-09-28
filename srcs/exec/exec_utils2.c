/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:33:13 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/28 14:28:16 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	rm_command_node(t_cmd **head, t_cmd *rm_node)
{
	t_cmd	*current;

	if (head == NULL || rm_node == NULL)
		return ;
	if (*head = rm_node)
	{
		head = rm_node->next;
		free(rm_node);
		return ;
	}
	current = *head;
	while (current->next != NULL && current->next != rm_node)
		current = current->next;
	if (current->next == NULL)
		return ;
	current->next = rm_node->next;
	free(rm_node);	
}

int	get_arg_len(t_token *arg)
{
	int		i;
	t_token	*ptr;

	ptr = arg;
	i = 0;
	while (ptr != 0)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
