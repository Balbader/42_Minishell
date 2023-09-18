#include "minishell.h"

static t_env	*env_create(char **env)
{
	t_env	*env_list;
	t_env	*head;
	int		env_len;
	char	*key;
	char	*value;
	int		i;

	env_list = ft_calloc(1, sizeof(t_env));
	if (!env_list)
		return (NULL);
	key = NULL;
	value = NULL;
	key = ft_copy_key(env[0], key, '=');
	value = ft_copy_value(env[0], value);
	env_list = ft_create_new_env_node(0, key, value);
	env_len = ft_get_env_len(env);
	head = env_list;
	i = 1;
	while (i <= env_len)
	{
		key = ft_copy_key(env[i], key, '=');
		value = ft_copy_value(env[i], value);
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
	return (&env_list);
}
