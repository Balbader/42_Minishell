#include "minishell.h"

int	exec_builtins(char *pth, t_cmd *cmd)
{
	int	ret;

	ret = false;
	if (ft_strcmp(path, "echo") == 0)
		//do_echo
	else if (ft_strcmp(path, "cd") == 0)
	else if (ft_strcmp(path, "pwd") == 0)
	else if (ft_strcmp(path, "export") == 0)
	else if (ft_strcmp(path, "unset") == 0)
	else if (ft_strcmp(path, "env") == 0)
	else if (ft_strcmp(path, "exit") == 0)
	return (ret);
}
