#include<stdio.h>
#include "libft.h"

void *borrar(void * ptr)
{
	ptr = NULL;
	return (ptr);
}

int main (void)
{
	t_list lista1;
	t_list lista2;
	t_list lista3;
	t_list lista4;
	t_list *ptr;
	
	ptr = &lista1;
	lista1.next = &lista2;
	lista2.next = &lista3;
	lista3.next = NULL;
	lista1.content = "Hola";
	lista2.content = "que tal";
	lista3.content = "ultimo";
	lista4.content = "NUEVA";
	
	printf("1*: %s\n2*:%s\n3*:%s",(char *)lista1.content,(char *) lista2.content, (char *)lista3.content);
	lista1 = ft_lstnew((char *)lista4->content);
	printf("1*: %s\n2*:%s\n3*:%s",(char *)lista1.content,(char *) lista2.content, (char *)lista3.content);

	ft_lstclear(&ptr,borrar(ptr));

	//printf("1*: %s\n2*:%s\n3*:%s",(char *)lista1.content,(char *) lista2.content, (    char *)lista3.content);

	return (0);
}

