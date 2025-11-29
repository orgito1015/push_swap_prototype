#include <stdio.h>
#include "push_swap.h"

void	bench_print(const t_env *env, const int *values, int n)
{
	double	d;

	d = compute_disorder(values, n) * 100.0;
	(void)env;
	fprintf(stderr, "[bench] disorder: %.2f%%\n", d);
	/* Extend this function to print strategy name, total ops, and per-op counts
	   once you hook op_counts into each operation. */
}
