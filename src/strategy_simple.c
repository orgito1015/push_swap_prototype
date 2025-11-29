#include "push_swap.h"

static int	find_min_index(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		idx;
	int		min_idx;
	int		i;

	cur = a->top;
	if (!cur)
		return (-1);
	min = cur->value;
	min_idx = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			min_idx = i;
		}
		cur = cur->next;
		i++;
	}
	return (min_idx);
}

void	run_simple(t_env *env)
{
	int	min_idx;
	int	i;

	while (env->a.size > 0)
	{
		min_idx = find_min_index(&env->a);
		if (min_idx < 0)
			break ;
		if (min_idx <= env->a.size / 2)
		{
			i = 0;
			while (i++ < min_idx)
				op_ra(env);
		}
		else
		{
			i = 0;
			while (i++ < env->a.size - min_idx)
				op_rra(env);
		}
		op_pb(env);
	}
	while (env->b.size > 0)
		op_pa(env);
}
