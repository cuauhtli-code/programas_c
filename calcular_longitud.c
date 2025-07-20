#include <stdio.h>
#include <string.h>

int calcular_longitud_de(char palabra[])
{
	size_t longitud = strlen(palabra);
	if (longitud > 0 && palabra[longitud - 1] == '\n')
	{
		palabra[longitud - 1] == '\0';
		longitud--;
	}
	return longitud;
}

void imprimir_longitud_de(char palabra[])
{
	int longitud = calcular_longitud_de(palabra);
	printf("%s tiene %d letras.\n", palabra, longitud);
}

int main()
{
	imprimir_longitud_de("hola mundo");
	return 0;
}
