#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMANO_MAX 1000

void contarYCambiarMayusMinus(char *);
void imprimirCambios(char *);

int main(void)
{
    char *texto = (char *)malloc(TAMANO_MAX * sizeof(char));

    while (1)
    {
        printf("\n--- Menu ---\n");
        printf("1. Ingresar un texto, contar y cambiar mayusculas/minusculas\n");
        printf("2. Imprimir cambios\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");

        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese un texto: ");
            getchar(); // Consumir el salto de línea pendiente
            fgets(texto, TAMANO_MAX, stdin);
            contarYCambiarMayusMinus(texto);
            break;
        case 2:
            imprimirCambios(texto);
            break;
        case 3:
            free(texto); // Liberar la memoria asignada antes de salir
            printf("Saliendo del programa.\n");
            exit(0);
        default:
            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
        }
    }

    return 0;
}

void contarYCambiarMayusMinus(char *texto)
{
    int mayusculas = 0, minusculas = 0;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (isupper(texto[i]))
        {
            mayusculas++;
            texto[i] = tolower(texto[i]);
        }
        else if (islower(texto[i]))
        {
            minusculas++;
            texto[i] = toupper(texto[i]);
        }
    }

    printf("Numero de mayusculas: %d\n", mayusculas);
    printf("Numero de minusculas: %d\n", minusculas);
}

void imprimirCambios(char *texto)
{
    printf("Contenido modificado almacenado en la memoria:\n");
    printf("%s\n", texto);
}
