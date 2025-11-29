#include <stdlib.h>
#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void	stack_clear(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	cur = s->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void	stack_push_top(t_stack *s, t_node *node)
{
	if (!node)
		return ;
	node->prev = NULL;
	node->next = s->top;
	if (s->top)
		s->top->prev = node;
	s->top = node;
	if (!s->bottom)
		s->bottom = node;
	s->size++;
}

t_node	*stack_pop_top(t_stack *s)
{
	t_node	*node;

	if (!s->top)
		return (NULL);
	node = s->top;
	s->top = node->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	node->next = NULL;
	node->prev = NULL;
	s->size--;
	return (node);
}
