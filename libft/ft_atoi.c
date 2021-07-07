#include "libft.h"

static unsigned long long	str_to_num(const char *start)
{
	unsigned long long	res;
	unsigned long long	rank;

	res = 0;
	rank = 1;
	while (ft_isdigit(*start))
		start++;
	start--;
	while (ft_isdigit(*start))
	{
		res += (*start - '0') * rank;
		rank *= 10;
		start--;
	}
	return (res);
}

int	ft_atoi(const char *nptr, int *overflow_flag)
{
	int					is_minus;
	unsigned long long	res;

	if (!(*nptr))
		return (0);
	is_minus = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_minus = -1;
		nptr++;
	}
	res = str_to_num(nptr);
	if ((is_minus == 1 && res > 2147483647) || (res > 2147483648))
		*overflow_flag = -1;
	return ((int)(res * is_minus));
}
