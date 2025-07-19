#include <stdio.h>

void saludar_a(char persona[])
{
	printf("Hola %s!", persona);
}

int main(void)
{	
	saludar_a("mundo");
	return 0;
}
