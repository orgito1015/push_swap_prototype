#include <unistd.h>
#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_node	*first;

	if (s->size < 2)
		return ;
	first = s->top;
	s->top = first->next;
	s->top->prev = NULL;
	first->next = NULL;
	first->prev = s->bottom;
	s->bottom->next = first;
	s->bottom = first;
}

void	op_ra(t_env *env)
{
	rotate(&env->a);
	write(1, "ra\n", 3);
}

void	op_rb(t_env *env)
{
	rotate(&env->b);
	write(1, "rb\n", 3);
}

void	op_rr(t_env *env)
{
	rotate(&env->a);
	rotate(&env->b);
	write(1, "rr\n", 3);
}
