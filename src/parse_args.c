#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_flag(const char *s)
{
	return (s[0] == '-' && s[1] == '-');
}

static void	set_flag(t_flags *flags, const char *s)
{
	if (!s)
		return ;
	if (!__builtin_strcmp(s, "--simple"))
		flags->strategy = STRAT_SIMPLE;
	else if (!__builtin_strcmp(s, "--medium"))
		flags->strategy = STRAT_MEDIUM;
	else if (!__builtin_strcmp(s, "--complex"))
		flags->strategy = STRAT_COMPLEX;
	else if (!__builtin_strcmp(s, "--adaptive"))
		flags->strategy = STRAT_ADAPTIVE;
	else if (!__builtin_strcmp(s, "--bench"))
		flags->bench = 1;
}

int	parse_args(int argc, char **argv, t_env *env, int *values, int *n_values)
{
	int	i;
	int	idx;
	int	val;

	i = 1;
	idx = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]))
			set_flag(&env->flags, argv[i]);
		else
		{
			if (!ps_atoi(argv[i], &val))
				return (0);
			values[idx++] = val;
			/* build stack a in same order */
			t_node *node = malloc(sizeof(t_node));
			if (!node)
				return (0);
			node->value = val;
			node->prev = NULL;
			node->next = NULL;
			stack_push_top(&env->a, node);
		}
		i++;
	}
	*n_values = idx;
	return (1);
}
