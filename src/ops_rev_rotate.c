#include <unistd.h>
#include "push_swap.h"

static void	rev_rotate(t_stack *s)
{
	t_node	*last;

	if (s->size < 2)
		return ;
	last = s->bottom;
	s->bottom = last->prev;
	s->bottom->next = NULL;
	last->prev = NULL;
	last->next = s->top;
	s->top->prev = last;
	s->top = last;
}

void	op_rra(t_env *env)
{
	rev_rotate(&env->a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_env *env)
{
	rev_rotate(&env->b);
	write(1, "rrb\n", 4);
}

void	op_rrr(t_env *env)
{
	rev_rotate(&env->a);
	rev_rotate(&env->b);
	write(1, "rrr\n", 4);
}
