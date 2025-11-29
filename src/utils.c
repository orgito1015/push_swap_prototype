#include <stdlib.h>
#include "push_swap.h"

int	ps_atoi(const char *s, int *out)
{
	long	sign;
	long	res;

	if (!s || !*s)
		return (0);
	sign = 1;
	res = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		res = res * 10 + (*s - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (0);
		s++;
	}
	*out = (int)(res * sign);
	return (1);
}

int	is_sorted_stack(const t_stack *s)
{
	t_node	*cur;

	if (!s || s->size <= 1)
		return (1);
	cur = s->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	env_init(t_env *env)
{
	int	i;

	stack_init(&env->a);
	stack_init(&env->b);
	env->flags.bench = 0;
	env->flags.strategy = STRAT_ADAPTIVE;
	i = 0;
	while (i < 11)
		env->op_counts[i++] = 0;
}

void	env_clear(t_env *env)
{
	stack_clear(&env->a);
	stack_clear(&env->b);
}
