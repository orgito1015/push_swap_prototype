#include "push_swap.h"

double	compute_disorder(const int *values, int n)
{
	long long	mistakes;
	long long	total;
	int			i;
	int			j;

	if (!values || n <= 1)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (values[i] > values[j])
				mistakes++;
			total++;
			j++;
		}
		i++;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}
