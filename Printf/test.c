#include <stdio.h>
int main(void)
{
    int        nbr;
    char     *str ="%@ %s%i \n" ;
    
    nbr = 42;
    printf(str, "nbr");
}
