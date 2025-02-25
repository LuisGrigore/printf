#include "print_nbr.h"
#include "print_str.h"
#include "print_char.h"

#include "symbols_config.h"
#include "max_values_config.h"
#include "libft.h"

int	print_nbr(long num)
{
	unsigned int	i;
	long			n;

	i = 0;
	n = (long) num;
	if (n == INT_MIN_VAL)
		return (print_str(ft_itoa(INT_MIN_VAL)));
	if (n < 0)
	{
		i += print_char(NEGATIVE_SYMBOL);
		n = -n;
	}
	if (n > 9)
	{
		i += print_nbr(n / 10);
		i += print_char(n % 10 + '0');
	}
	else
		i += print_char(n + '0');
	return (i);
}