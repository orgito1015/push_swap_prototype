#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static void	choose_strategy_and_run(t_env *env, const int *values, int n)
{
	if (env->flags.strategy == STRAT_SIMPLE)
		run_simple(env);
	else if (env->flags.strategy == STRAT_MEDIUM)
		run_medium(env);
	else if (env->flags.strategy == STRAT_COMPLEX)
		run_complex(env);
	else
		run_adaptive(env, values, n);
	if (env->flags.bench)
		bench_print(env, values, n);
}

int	main(int argc, char **argv)
{
	t_env	env;
	int		*values;
	int		n_values;

	if (argc <= 1)
		return (0);
	env_init(&env);
	values = malloc(sizeof(int) * (argc - 1));
	if (!values)
		return (1);
	if (!parse_args(argc, argv, &env, values, &n_values))
	{
		write(2, "Error\n", 6);
		free(values);
		env_clear(&env);
		return (1);
	}
	if (!is_sorted_stack(&env.a))
		choose_strategy_and_run(&env, values, n_values);
	free(values);
	env_clear(&env);
	return (0);
}
