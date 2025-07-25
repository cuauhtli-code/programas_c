#include <stdio.h>

#define DENTRO 1
#define FUERA 0

int main ()
{
	int caracter;
	int posicion;
	int limite = 101; // limite de caracteres
	char cadena[limite];

	/* Empezamos en la posicion 0. Si el caracter que leimos no es el final
	del archivo y aun no hemos llegado al limite, guardamos el caracter en
	la cadena y avanzamos de posicion (incluyendo a los delimitadores) */
	
	printf("Presiona \'Ctrl-C\' cuando termines de escribir la linea.\n");
	for (posicion = 0; (caracter = getchar()) != EOF && posicion < limite; posicion++)
	{
		cadena[posicion] = caracter;

		if (caracter == '\n' && caracter == '\t' && caracter == ' ')
		{
			cadena[posicion] = caracter;
		}
	}

	cadena[posicion] = '\0'; // par que '%s' funcione correctamente

	int estado = FUERA;
	char palabra[limite];
	char palabra_mas_larga[limite];
	int cantidad_letras = 0;
	int max = 0;
	int letras = 0;

	/* Recorre toda la cadena y guarda el caracter en 'caracter' mientras no este vacio.
	Si el caracter no es un delimitador, esta dentro de un palabra, asi que guarda los
	caracteres de esa palabra en 'palabra' al mismo tiempo que cuenta las letras que
	tiene esa palabra.

	De lo contrario si viene de una palabra, cierra la palabra y verifica si es la mas
	larga que ha visto. Sí si, la guarda en 'palabra_mas_larga', reinicia la cantidad
	de letras y 'estado == FUERA' (porque no estamos dentro de una palabra) */
	
	for (posicion = 0; cadena[posicion] != '\0'; posicion++)
	{
		caracter = cadena[posicion];
		
		if (caracter != '\n' && caracter != ' ' && caracter != '\t')
		{
			estado = DENTRO;
			palabra[cantidad_letras++] = caracter;
		}
		else
		{
			if (estado == DENTRO)
			{
				palabra[cantidad_letras] = '\0'; // cerramos la palabra

				if (cantidad_letras > max)
				{
					max = cantidad_letras;
				}

				int j;

				for (j = 0; j < cantidad_letras; j++)
				{
					palabra_mas_larga[j] = palabra[j];
					letras = cantidad_letras;
				}

				cantidad_letras = 0;
				estado = FUERA;
			}
		}
	}

	printf("\n\n%s\n\'%s\' es la palabra mas larga.\nTeniendo %d letras.", cadena, palabra_mas_larga, letras);	
	
	return 0;	
}
