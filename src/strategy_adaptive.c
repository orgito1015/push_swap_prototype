#include "push_swap.h"

void	run_adaptive(t_env *env, const int *values, int n)
{
	double	disorder;

	(void)values;
	disorder = compute_disorder(values, n);
	/* Simple decision rule placeholder. You can refine thresholds and strategies. */
	if (disorder < 0.2)
		run_simple(env);
	else if (disorder < 0.5)
		run_medium(env);
	else
		run_complex(env);
}
