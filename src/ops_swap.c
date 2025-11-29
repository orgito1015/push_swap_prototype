#include <unistd.h>
#include "push_swap.h"

static void	swap_top(t_stack *s)
{
	int	tmp;

	if (!s->top || !s->top->next)
		return ;
	tmp = s->top->value;
	s->top->value = s->top->next->value;
	s->top->next->value = tmp;
}

void	op_sa(t_env *env)
{
	swap_top(&env->a);
	write(1, "sa\n", 3);
}

void	op_sb(t_env *env)
{
	swap_top(&env->b);
	write(1, "sb\n", 3);
}

void	op_ss(t_env *env)
{
	swap_top(&env->a);
	swap_top(&env->b);
	write(1, "ss\n", 3);
}
