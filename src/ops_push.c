#include <unistd.h>
#include "push_swap.h"

void	op_pa(t_env *env)
{
	t_node	*node;

	node = stack_pop_top(&env->b);
	if (!node)
		return ;
	stack_push_top(&env->a, node);
	write(1, "pa\n", 3);
}

void	op_pb(t_env *env)
{
	t_node	*node;

	node = stack_pop_top(&env->a);
	if (!node)
		return ;
	stack_push_top(&env->b, node);
	write(1, "pb\n", 3);
}
