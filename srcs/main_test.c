#include "minishell.h"

int	g_error;

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_env	*new_env;

	new_env = NULL;
	new_env = *ft_get_env(env, NULL, NULL);
	while (new_env)
	{
		printf("var : %s\n", new_env->var);
		printf("key : %s\n", new_env->key);
		printf("value : %s\n", new_env->value);
		new_env = new_env->next;
	}
	return (0);
}
