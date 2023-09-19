/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:34:46 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 16:34:48 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_del_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tmp)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->word);
		free(tmp->type);
		free(tmp);
	}
}
