#include<stdio.h>
#include <string.h>
//size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);

int main(void)
{
	char dst[7] = "hola";
	printf("%lu", strlcat(dst,"src", 0));
	printf("%s",dst);
	return 0;
}
