#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void minymay(FILE *, char **, int *);

int main(void)
{
    FILE *entrada;

    // Reemplaza "/ruta/completa/" con la ruta real del directorio donde se encuentran los archivos
    const char *rutaEntrada = "prueba.txt";

    // Abrir el archivo de entrada para lectura
    if ((entrada = fopen(rutaEntrada, "r")) == NULL)
    {
        printf("No se pudo abrir el archivo de entrada %s\n", rutaEntrada);
        return 1; // Devolver un código de error
    }

    char *contenido = NULL;
    int tamano = 0;

    minymay(entrada, &contenido, &tamano);

    // Cerrar el archivo de entrada
    fclose(entrada);

    // Imprimir el contenido modificado
    printf("%s", contenido);

    // Guardar el contenido modificado en un archivo
    FILE *salida;
    const char *rutaSalida = "salida.txt";

    // Abrir el archivo de salida para escritura
    if ((salida = fopen(rutaSalida, "w")) == NULL)
    {
        printf("No se pudo abrir el archivo de salida %s\n", rutaSalida);
        free(contenido); // Liberar la memoria asignada
        return 1; // Devolver un código de error
    }

    // Escribir el contenido en el archivo de salida
    fprintf(salida, "%s", contenido);

    // Cerrar el archivo de salida
    fclose(salida);

    // Liberar la memoria asignada
    free(contenido);

    return 0;
}

void minymay(FILE *entrada, char **contenido, int *tamano)
{
    int min = 0, may = 0;
    char p;

    while ((p = fgetc(entrada)) != EOF)
    {
        if (islower(p))
        {
            may++;
            p = toupper(p); // Convierte minúscula en mayúscula
        }
        else if (isupper(p))
        {
            min++;
            p = tolower(p); // Convierte mayúscula en minúscula
        }

        (*tamano)++;
        *contenido = (char *)realloc(*contenido, *tamano * sizeof(char));

        if (*contenido == NULL)
        {
            printf("Error al asignar memoria");
            exit(1); // Salir con un código de error
        }

        (*contenido)[(*tamano) - 1] = p; // Almacenar el carácter modificado
    }

    // Terminar la cadena con el carácter nulo
    (*tamano)++;
    *contenido = (char *)realloc(*contenido, *tamano * sizeof(char));

    if (*contenido == NULL)
    {
        printf("Error al asignar memoria");
        exit(1); // Salir con un código de error
    }

    (*contenido)[(*tamano) - 1] = '\0';

    // Imprimir el número de letras minúsculas y mayúsculas
    printf("Numero de minusculas: %d\n", min);
    printf("Numero de mayusculas: %d\n", may);
}
