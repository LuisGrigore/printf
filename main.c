#include "ft_printf.h"
#include <stdio.h>



int main(int argc, char const *argv[])
{
	int *a,*b;

	*a = 1;
	*b = 2;
	ft_printf("%dHOLA que tal%dhola %d asda%%%d",a,b,a,b);
	return 0;
}

