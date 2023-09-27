#include "minishell.h"

void	display_err(char *err_str)
{
	ft_putstr_fd(err_str, STDERR_FILENO);
	ft_putstr_fd("REPLACE BY REAL ERR MANAGEMENT\n", STDERR_FILENO);
}
