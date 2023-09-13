#include "expand.h"

t_token	*cmd_lstndup(t_token *cmd_line, t_token *last)
{
	t_token	*cmd_dup;
	t_token	*ptr;

	ptr = cmd_line->next;
	while (ptr != last)
	{
		cmd_dup = cmdline_new_node(cmd_line->word);
		if (!cmd_dup)
			return (NULL);
		
	}	
}
