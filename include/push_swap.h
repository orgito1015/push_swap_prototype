#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef enum e_strategy
{
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_flags
{
	int			bench;
	t_strategy	strategy;
}	t_flags;

typedef struct s_env
{
	t_stack		a;
	t_stack		b;
	t_flags		flags;
	long long	op_counts[11];
}	t_env;

/* parse_args.c */
int		parse_args(int argc, char **argv, t_env *env, int *values, int *n_values);

/* stack.c */
void	stack_init(t_stack *s);
void	stack_clear(t_stack *s);
void	stack_push_top(t_stack *s, t_node *node);
t_node	*stack_pop_top(t_stack *s);

/* ops_swap.c */
void	op_sa(t_env *env);
void	op_sb(t_env *env);
void	op_ss(t_env *env);

/* ops_push.c */
void	op_pa(t_env *env);
void	op_pb(t_env *env);

/* ops_rotate.c */
void	op_ra(t_env *env);
void	op_rb(t_env *env);
void	op_rr(t_env *env);

/* ops_rev_rotate.c */
void	op_rra(t_env *env);
void	op_rrb(t_env *env);
void	op_rrr(t_env *env);

/* disorder.c */
double	compute_disorder(const int *values, int n);

/* strategies */
void	run_simple(t_env *env);
void	run_medium(t_env *env);
void	run_complex(t_env *env);
void	run_adaptive(t_env *env, const int *values, int n);

/* bench.c */
void	bench_print(const t_env *env, const int *values, int n);

/* utils.c */
int		ps_atoi(const char *s, int *out);
int		is_sorted_stack(const t_stack *s);
void	env_init(t_env *env);
void	env_clear(t_env *env);

#endif
