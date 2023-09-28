#include "minishelltools.h"

char	*copy_path(char **envp)
{
	int		i;
	char	*path_copy;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_copy = ft_strdup(envp[i] + 5);
			return (path_copy);
		}
		i++;
	}
	return (NULL);
}

char	**create_path(char **envp)
{
	char	*strdup_path;
	char	**split_path;
	char	**comp_path;

	if (envp == NULL)
	{
		ft_putstr_fd("envp error\n", 2);
		exit(127);
	}
	strdup_path = copy_path(envp);
	split_path = ft_split(strdup_path, ':');
	comp_path = loop_joinf(split_path, "/");
	free(strdup_path);
	return (comp_path);
}

char	*init_path(char *cmd, char **envp)
{
	char	**paths;
	char	*individual_path;
	t_list	*dump;
	int		i;

	paths = create_path(envp);
	dump = ft_calloc(1, sizeof(t_list));
	add_str_to_dump(paths, dump);
	i = 0;
	while (paths[i] != 0)
	{
		individual_path = ft_strjoin(paths[i], cmd);
		if (access(individual_path, X_OK) == 0)
		{
			dump_del(dump);
			return (individual_path);
		}
		dump_add(individual_path, dump);
		i++;
	}
	dump_del(dump);
	return (0);
}