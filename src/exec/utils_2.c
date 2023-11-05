
#include "../../includes/minishell.h"

void	closepipe_andwait(t_exec_p *exec, t_v *v)
{
	v->i = 0;
	while (v->i < v->pipe_num * 2)
		close(exec->p[v->i++]);
	v->i = 0;
	while (v->i < v->pipe_num)
	{
		waitpid(0, &v->status, 0);
		if (!in_builtin(v->tmp))
			g_data.exitcode = WEXITSTATUS(v->status);
		v->tmp = v->tmp->next;
		v->i++;
	}
	free(exec->p);
	free (exec);
}
