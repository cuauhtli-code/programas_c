#include <stdio.h>
#include <string.h>

/* mientras el caracter no sea un salto de linea o el final del 
archivo, la funcion seguira limpiando el buffer */

void limpiar_buffer()
{	
	int caracter;
	while ((caracter = getchar()) != '\n' && caracter != EOF);
}

/* 'cantidad leida' guarda el valor de 'cantidad', sí no es 1 (entero)
se mandara un mensaje de error y permitira reingresar la cantidad

y si la cantidad que ingresó el usuario es menor a 0 también se mandara
mandara un mensaje de error y permitirá reingresar la cantidad 

hasta que el usuario ingresa un tipo de dato valido se rompera el ciclo */

int leer_cantidad_palabras(const char *mensaje)
{
	int cantidad, cantidad_leida;
	while (1)
	{
		printf("%s", mensaje);
		cantidad_leida = scanf("%d", &cantidad);
		if (cantidad_leida != 1)
		{
			printf("	-> Error: Tipo de dato no valido.\n");
			limpiar_buffer();
			continue;
		}
		if (cantidad <= 0)
		{
			printf("	-> Error: No se permite numero negativos.\n");
			limpiar_buffer();
			continue;
		}
		break;
	}
	return cantidad;
}

/* esta funcion calcula la longitud de la palabra que se le ingrese como parametro

'len' guarda la longitud de la palabra, y sí es mayor a 0 pero la ultima letra es un 
salto de linea, se elimina ese salto de linea y se reduce su longitud */

int calcular_longitud(char palabra[])
{
	size_t len = strlen(palabra);
	if (len > 0 && palabra[len - 1] == '\n')
	{
		palabra[len - 1] == '\0';
		len--;
	}
	return len;
}

/* 'indice' representa la posicion del arreglo en la que se guarda la palabra,
y 'char palabra[]' representa el arreglo en donde se guardara esa palabra

si la longitud de la palabra es 0 (sí el usuario presionó Enter), se mandará un
mensaje de error y permitirá reingresar la palabra */

void leer_palabra(int indice, char palabra[])
{
	while (1)
	{
		printf("Palabra %d: ", indice + 1);
		fgets(palabra, 31, stdin);
		int len = calcular_longitud(palabra);
		if (len == 0)
		{
			printf("	-> Error: Cadena vacia (salto de linea).\n");
			continue;
		}
		break;
	}
}

int main()
{	
	// 'cantidad_palabras' guarda el valor que leyó la función 'leer_cantidad_palabras'
	
	int cantidad_palabras = leer_cantidad_palabras("> ");

	// cantidad_palabras | '31' es el limite de letras que pueden tener cada una de las palabras
	 
	char arreglo[cantidad_palabras][31];

	// lee cada palabra y la guarda en el arreglo

	int indice;
	for (indice = 0; indice < cantidad_palabras; indice++)
	{
		leer_palabra(indice, arreglo[indice]);
	}

	/* 'palabra_mas_larga' es la mayor, y 'palabra_mas_corta' es la menor, pero si la
	hay una mayor, automaticamente pasa a ser 'palabra_mas_larga'

	es la misma logica para la menor */
	
	char *palabra_mas_larga = arreglo[0];
	char *palabra_mas_corta = arreglo[0];

	for (indice = 1; indice < cantidad_palabras; indice++)
	{
		if (calcular_longitud(arreglo[indice]) > calcular_longitud(palabra_mas_larga))
		{
			palabra_mas_larga = arreglo[indice];
		}
		if (calcular_longitud(arreglo[indice]) < calcular_longitud(palabra_mas_corta))
		{
			palabra_mas_corta = arreglo[indice];
								
		}
	}

	printf("\nLista de palabras:\n");

	for (indice = 0; indice < cantidad_palabras; indice++)
	{
		printf("%d. %s, con %d letras.\n", indice + 1, arreglo[indice], calcular_longitud(arreglo[indice]));
	}

	printf("\nLa palabras mas larga del arreglo es \"%s\", y la mas corta es \"%s\"", palabra_mas_larga, palabra_mas_corta);
	
	return 0;
}
