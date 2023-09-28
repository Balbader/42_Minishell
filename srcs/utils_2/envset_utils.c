/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envset_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:54:52 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/27 15:44:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//debug function
int ft_printenv(t_env *env)
{
    t_env *tmp;

    if (!env)
        return (FAILURE);
    tmp = env;
    while (tmp)
    {
        printf("coucou, key = %p value = %p\n", tmp->key, tmp->value);
        if (tmp->value != NULL)
        {
            printf("KEY = %s\n", tmp->key);
            printf("VALUE = %s\n", tmp->value);
        }
        tmp = tmp->next;
    }
    return (SUCCESS);
}

/*
t_env *env_create(char **env)
{
    t_env *env_list = NULL;
    t_env *head = NULL;
    int env_len = ft_get_env_len(env);
    char *key = NULL;
    char *value = NULL;
    int i = 0;

    while (i < env_len)
    {
        key = ft_copy_key(env[i], key, '=');
        value = ft_copy_value(env[i], value);
        if (i == 0)
        {
            env_list = ft_create_new_env_node(0, key, value);
            head = env_list;
        }
        else
        {
            env_list->next = ft_create_new_env_node(i, key, value);
            env_list = env_list->next;
        }
        i++;
    }
    return (head); 
}
*/

t_env **get_env(char **env)
{
/*    static t_env *env_list = NULL;

    if (env_list == NULL && env != NULL)
    {
        env_list = env_create(env);
    }
    return (&env_list);
*/
	return (ft_get_env(env));
}



/*
int	ft_printenv(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return (FAILURE);
	tmp = env;
	while (tmp)
	{
printf("coucou, key = %p value = %p\n", tmp->key, tmp->value);
		if (tmp->value != NULL)
		{
			printf("KEY = %s\n", tmp->key);
			printf("VALUE = %s\n", tmp->value);
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

 t_env	*env_create(char **env)
{
	t_env	*env_list;
	t_env	*head;
	int		env_len;
	char	*key;
	char	*value;
	int		i;

	key = NULL;
	value = NULL;
	env_len = ft_get_env_len(env);
	i = 0;
	while (i <= env_len)
	{
		key = ft_copy_key(env[i], key, '=');
		value = ft_copy_value(env[i], value);
		if (i == 0)
		{
			env_list = ft_create_new_env_node(0, key, value);
			head = env_list;
		}
		env_list->next = ft_create_new_env_node(i, key, value);
		env_list = env_list->next;
		i++;
	}
	return (env_list);
}

t_env	**get_env(char **env)
{
	static t_env	*env_list = NULL;

	if (env != NULL)
		env_list = env_create(env);
	return (env_list);
}
*/
