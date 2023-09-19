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
	t_env	*env_lst = NULL;
	int		env_len;
	t_token	*tokens = NULL;
	t_token	*new_token = NULL;

	tokens = ft_init_tokens(tokens);
	env_len = ft_get_env_len(env);
	env_lst = *(ft_get_env(env));
	new_token = ft_create_token("key=4", 4);

	ft_export_many_args(tokens, env_lst);
	ft_exec_env(env_lst, 1);

	int		does_exist = 0;
	does_exist = ft_does_key_exist(new_token->word, env_lst);
	printf("does exist : %d\n", does_exist);
	ft_del_env(env_lst);
	return (0);
}
