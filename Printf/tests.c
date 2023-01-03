#include <stdio.h>
int main(void)
{
    int        nbr;
    char     *str ="%@ %s%i \n" ;
    
    nbr = 42;
    printf(str, "nbr");
}

//Tests_list:

	printf("\n%i\n", ft_printf("%x", 1254));
	printf("\n%i\n", printf("%x", 1254));
	printf("\n%i\n", ft_printf("%1c", 'a'));
	printf("\n%i\n", printf("%1c", 'a'));
	printf("%i\n", ft_printf(" %x %x %x %x %x %x %x", 0, 16, 32, LONG_MIN, ULONG_MAX, 64, -42));
	printf("%i\n", ft_printf(" %x %x %x %x %x %x ", 1, 1, 1, 1, 1, 1, 1));
	printf("%i\n", printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

