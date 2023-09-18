/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:31:52 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/08 10:31:53 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Welcome to the builtins branch
 * new
*/

#include "minishell.h"

t_token	*ft_create_token(char *arg, int i)
{
	t_token	*token;

	token = NULL;
	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->word = arg;
	token->type = i;
	token->next = NULL;
	return (token);
}

t_token	*ft_init_tokens(t_token *token)
{
	t_token	*head= NULL;

	token = ft_create_token("export", 0);
	head = token;
	token->next = ft_create_token("key=1", 1);
	token = token->next;
	token->next = ft_create_token("key=2", 2);
	token = token->next;
	token->next = ft_create_token("key=3", 3);
	token = token->next;
	return (head);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env	*env_list = NULL;
	int		env_len;
	t_token	*tokens = NULL;
	int token_len;

	tokens = ft_init_tokens(tokens);
	token_len = ft_get_token_len(tokens);
	printf("token_len: %d\n", token_len);
	for (int i = 0; i < token_len; ++i) {
		printf("tokens[%d]->word : %s\n", tokens->type, tokens->word);
		tokens = tokens->next;
	}
	env_len = ft_get_env_len(env);
	env_list = *(ft_get_env(env));
	// ft_exec_env(env_list, 1);
	ft_del_env(env_list);
	return (0);
}
