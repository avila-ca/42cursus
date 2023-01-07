#include <stdio.h>

char *ft_itoa(int n);
int ft_counter(int n);
void *ft_calloc(size_t count, size_t size);

int main (void)
{
	int a;

	a = -2147483648;
	printf("el  nummero: %d\n%d digitos >>>> resolviendo >>>>> \n", a, ft_counter(a));
	printf("string: %s", ft_itoa(a));
	return(0);
}
